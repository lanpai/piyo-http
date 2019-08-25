#include "Request.h"

#include <cstdio>
#include <sstream>

Request::Request(const char* request) {
    std::istringstream linestream(request);

    std::string line;
    int lineNum = 0;
    while (std::getline(linestream, line)) {
        std::istringstream blockstream(line);

        if (lineNum == 0) {
            blockstream >> method >> path >> protocol;
        }
        else {
            std::string key;
            blockstream >> key;

            if (!!key.length() && key.at(key.length() - 1) == ':') {
                key.pop_back();

                std::string value;
                while (blockstream >> value);

                this->headers[key] = value;
            }
        }

        lineNum++;
    }
}
