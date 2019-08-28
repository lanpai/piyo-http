#include "Message.h"

void
Message::SetHeader(const std::string &header, const std::string &value) {
    this->headers[header] = value;
}

const std::string
Message::GetHeader(const std::string &header) {
    std::map<std::string, std::string>::iterator value = this->headers.find(header);
    if (value == this->headers.end())
        return NULL;
    return value->second;
}
