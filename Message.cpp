#include "Message.h"

void
Message::SetHeader(const std::string &header, const std::string &value) {
    this->headers[header] = value;
}

const std::string
Message::GetHeader(const std::string &header) {
    return this->headers[header];
}
