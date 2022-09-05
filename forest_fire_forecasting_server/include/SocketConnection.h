#ifndef SOCKETCONNECTION_H
#define SOCKETCONNECTION_H
#include "NetworkServer.h"
#include <iostream>
#include <string>
#include <utility>
#include <cstdarg>
#include "../../web-socket/easy-socket-master/include/masesk/EasySocket.hpp"

using namespace std;

class SocketConnection : public NetworkServer {
    public:
        static SocketConnection* getInestance();
        virtual bool establishConnection();
        virtual bool sendPayload(int count, ...);

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
