#include "Response.h"

#include <unistd.h>
#include <thread>

Response::Response(int sockfd) {
    this->sockfd = sockfd;
    this->isClosed = false;

    SetHeader("Server", "piyoHTTP");
    SetHeader("Connection", "keep-alive");
}

const std::string
Response::GetStatusDesc(int code) const {
    switch (code) {
        case StatusCode::OK:
            return "200 OK";
        case StatusCode::NOT_FOUND:
            return "404 Not Found";
        case StatusCode::INTERNAL_SERVER_ERROR:
            return "500 Internal Server Error";
        default:
            std::printf("Unregistered status code (%d)\n", code);
            return std::to_string(code);
    }
}

void
Response::WriteHead(int code) {
    if (!this->isClosed) {
        std::string buffer;

        buffer += "HTTP/1.1 " + GetStatusDesc(code) + '\n';

        for (std::map<std::string, std::string>::iterator it = this->headers.begin();
                it != this->headers.end();
                it++) {
            buffer += it->first + ": " + it->second + "\n";
        }
        buffer += "\r\n";

        if (write(this->sockfd, buffer.c_str(), buffer.length()) < 0) {
            std::perror("write()");
        }
    }
}

void
Response::Write(std::string content) {
    if (!this->isClosed) {
        if (write(this->sockfd, content.c_str(), content.length()) < 0) {
            std::perror("write()");
        }
    }
}

void
Response::End(std::string content) {
    if (!this->isClosed) {
        if (write(this->sockfd, content.c_str(), content.length()) < 0) {
            std::perror("write()");
        }

        if (close(this->sockfd) < 0) {
            std::perror("close()");
        }
        this->isClosed = true;
    }
}
