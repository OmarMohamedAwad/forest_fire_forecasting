#ifndef SOCKETCONNECTION_H
#define SOCKETCONNECTION_H
#include "NetworkServer.h"
#include <iostream>
#include <string>

using namespace std;

class SocketConnection : public NetworkServer {
    public:
        static SocketConnection* getInestance();
        virtual bool establishConnection();

    protected:

    private:
        string channel;
        int socketPort;
        string socketIp;
        SocketConnection();
        static SocketConnection *instance;
        void parseNetworkData(string handCheckData);
};

#endif // SOCKETCONNECTION_H
