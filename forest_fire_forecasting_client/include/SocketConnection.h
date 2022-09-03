#ifndef SOCKETCONNECTION_H
#define SOCKETCONNECTION_H
#include "NetworkClient.h"
#include <iostream>
#include <string>

using namespace std;

class SocketConnection : public NetworkClient {
    public:
        static SocketConnection* getInestance();
        virtual bool establishConnection();
        bool serverResponse();
        string getServerChannel();
        string getServerIp();
        int getServerPort();
        void setServerChannel(string channel);
        void setServerPort(int port);
        void setServerIp(string ip);

    protected:

    private:
        string channel;
        int socketPort;
        string socketIp;
        string serverChannel;
        int serverPort;
        string serverIp;
        SocketConnection();
        static SocketConnection *instance;
        void parseNetworkData(string handCheckData);
};

#endif // SOCKETCONNECTION_H
