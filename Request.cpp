#include "Request.h"

#include <cstdio>
#include <sstream>

Request::Request(const char* request) {
    std::istringstream linestream(request);

    std::string line;
    int lineNum = 0;
    std::printf("------------------------------\n");
    while (std::getline(linestream, line)) {
        std::printf("%s\n", line.c_str());
        std::istringstream blockstream(line);

        if (lineNum == 0) {
            blockstream >> method >> path >> protocol;
        }
        else {
            std::string key;
            blockstream >> key;

            if (key.length() > 0 && key.at(key.length() - 1) == ':') {
                key.pop_back();

                std::string value;
                std::string block;
                while (blockstream >> block)
                    value += block + ' ';
                if (value.length() > 0)
                    value.pop_back();

                this->headers[key] = value;
            }
        }

        lineNum++;
    }
    std::printf("------------------------------\n");
}
