#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H
#include <iostream>
#include <string>

using namespace std;

class NetworkServer
{
     public:
        NetworkServer();
        string getData();
        void setData(string data);
        virtual bool establishConnection() = 0;
        virtual bool sendPayload(int count, ...) = 0;

    protected:
        string payloadData;

    private:

};

#endif // NETWORKSERVER_H
