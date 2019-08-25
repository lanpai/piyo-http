#ifndef __PIYOHTTP_H
#define __PIYOHTTP_H

class piyoHTTP {
    public:
        piyoHTTP();
        ~piyoHTTP();

        int Listen(int port);

    private:
        int sockfd;
};

#endif
