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
        string getValue();
        string getKey();

    protected:

    private:
        SocketConnection();
        static SocketConnection *instance;
        void parseNetworkData(string handCheckData);
        string key;
        string value;
};

#endif // SOCKETCONNECTION_H
