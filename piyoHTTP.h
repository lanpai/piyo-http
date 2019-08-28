#ifndef __PIYOHTTP_H
#define __PIYOHTTP_H

#include <vector>
#include <thread>

#include "Request.h"
#include "Response.h"

#define MAX_THREADS 500

class piyoHTTP {
    public:
        piyoHTTP();
        ~piyoHTTP();

        void Listen(int port);

        void OnRequest(Request req, Response res, int i);

    private:
        int sockfd;

        bool isRunning;

        std::thread threads[MAX_THREADS];
        bool openThreads[MAX_THREADS];
        int threadIter;
};

#endif
