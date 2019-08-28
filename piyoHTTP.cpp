#include "piyoHTTP.h"

#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <fstream>
#include <signal.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "MIME.h"

piyoHTTP::piyoHTTP() {
    if ((this->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::perror("socket()");
        exit(EXIT_FAILURE);
    }

    this->threadIter = 0;

    for (int i = 0; i < MAX_THREADS; i++)
        this->openThreads[i] = true;
}

piyoHTTP::~piyoHTTP() {
    std::printf("Closing all threads...");

    this->isRunning = false;
    for (int i = 0; i < MAX_THREADS; i++) {
        if (this->threads[i].joinable())
            this->threads[i].join();
    }

    if (close(this->sockfd) < 0) {
        std::perror("close()");
        exit(EXIT_FAILURE);
    }
}

void
piyoHTTP::OnRequest(Request req, Response res, int i) {
    std::printf("thread id: %d\n", i);
    std::printf("host: %s\n%s %s %s\n",
            req.GetHeader("Host").c_str(),
            req.GetMethod().c_str(),
            req.GetPath().c_str(),
            req.GetProtocol().c_str());

    UpdateMIME("html", res);

    std::printf("User-Agent: %s\n", req.GetHeader("User-Agent").c_str());

    std::ifstream resource("./static/" + req.GetPath());

    if (resource.fail()) {
        res.WriteHead(404);
        res.End("<p>404 Not Found</p>");
        return;
    }

    std::string content;
    std::string line;
    while (resource.good()) {
        resource >> line;
        content += line + '\n';
    }
    resource.close();

    res.WriteHead(200);
    res.End(content);

    this->openThreads[i] = true;
}

void
piyoHTTP::Listen(int port) {
    struct sockaddr_in serv_addr;

    int opt = 1;
    if (setsockopt(this->sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        std::perror("setsockopt()");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(this->sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        std::perror("bind()");
        exit(EXIT_FAILURE);
    }

    listen(this->sockfd, 5);

    signal(SIGPIPE, SIG_IGN);

    this->isRunning = true;
    while (this->isRunning) {
        struct sockaddr_in cli_addr;
        int newsockfd;
        int clilen = sizeof(cli_addr);

        if ((newsockfd = accept(this->sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen)) < 0) {
            std::perror("accept()");
            continue;
        }

        char buffer[8192];
        if (read(newsockfd, buffer, 8192) < 0) {
            std::perror("accept()");
            continue;
        }

        Request req(buffer);
        if (!(  req.GetProtocol() == "HTTP/1.1" ||
                req.GetProtocol() == "HTTP/1.0" ||
                req.GetProtocol() == "HTTP/2.0")) {
            continue;
        }

        Response res(newsockfd);

        int i = this->threadIter;
        while (true) {
            if (this->openThreads[i]) {
                std::printf("checking %d\n", i);
                if (this->threads[i].joinable())
                    this->threads[i].join();
                this->openThreads[i] = false;
                this->threadIter = i;
                this->threads[i] = std::thread(&piyoHTTP::OnRequest, this, req, res, i);
                break;
            }
            if (++i >= MAX_THREADS)
                i = 0;
        }
    }
}
