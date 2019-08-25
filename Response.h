#ifndef __RESPONSE_H
#define __RESPONSE_H

#include <string>

#include "Message.h"

enum StatusCode {
    OK = 200,
    NOT_FOUND = 404,
    INTERNAL_SERVER_ERROR = 500
};

class Response : public Message {
    public:
        Response(int sockfd);

        const std::string GetStatusDesc(int code) const;

        void WriteHead(int code = StatusCode::OK);
        void End(std::string content);

    private:
        int sockfd;
};

#endif
