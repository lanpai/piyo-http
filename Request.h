#ifndef __REQUEST_H
#define __REQUEST_H

#include <map>
#include <string>

#include "Message.h"

class Request : public Message {
    public:
        Request(const char* request);

        const std::string GetMethod() const { return this->method; };
        const std::string GetPath() const { return this->path; };
        const std::string GetProtocol() const { return this->protocol; }

    private:
        std::string method;
        std::string path;
        std::string protocol;
};

#endif
