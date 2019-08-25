#ifndef __MESSAGE_H
#define __MESSAGE_H

#include <string>
#include <map>

class Message {
    public:
        void SetHeader(const std::string &header, const std::string &value);
        const std::string GetHeader(const std::string &header);

    protected:
        std::map<std::string, std::string> headers;
};

#endif
