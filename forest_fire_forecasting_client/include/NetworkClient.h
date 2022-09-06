#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H
#include <map>
#include <string>
#include <iostream>

using namespace std;

class NetworkClient
{
     public:
        NetworkClient();
        virtual bool establishConnection() = 0;
        string getPayload();
        void setPayload(string payload);

    protected:
        string payload;

    private:
};

#endif // NETWORKCLIENT_H
