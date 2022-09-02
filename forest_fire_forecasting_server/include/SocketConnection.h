#ifndef SOCKETCONNECTION_H
#define SOCKETCONNECTION_H
#include "NetworkServer.h"


class SocketConnection : public NetworkServer {
    public:
        static SocketConnection* getInestance();
        virtual bool establishConnection();

    protected:

    private:
        SocketConnection();
        static SocketConnection *instance;
};

#endif // SOCKETCONNECTION_H
