#ifndef SOCKETCONNECTION_H
#define SOCKETCONNECTION_H
#include "NetworkClient.h"
#include <iostream>
#include <string>
#include <utility>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

using namespace std;

class SocketConnection : public NetworkClient {
    public:
        mutex mtx;
        static SocketConnection* getInestance();
        virtual bool establishConnection();
        bool serverResponse();
        string getServerChannel();
        string getServerIp();
        int getServerPort();
        void setServerChannel(string channel);
        void setServerPort(int port);
        void setServerIp(string ip);
        void handelConnection(string channel, string ip, int port);

    protected:

    private:
        string channel;
        int socketPort;
        string socketIp;
        string serverChannel;
        int serverPort;
        string serverIp;
        static SocketConnection *instance;
        SocketConnection();
        void parseNetworkData(string handCheckData);
};

#endif // SOCKETCONNECTION_H
