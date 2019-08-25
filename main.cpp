#include <stdlib.h>
#include <cstdio>

#include "piyoHTTP.h"

#define DEFAULT_PORT 8653

int main(int argc, char** argv) {
    int port;
    if (argc > 1 && argv[1])
        port = atoi(argv[1]);
    else
        port = DEFAULT_PORT;

    piyoHTTP server;
    std::printf("Listening on port %d\n", port);
    server.Listen(port);

    return 0;
}
