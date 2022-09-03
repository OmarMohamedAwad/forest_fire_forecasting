#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H
#include <string>

using namespace std;

class NetworkServer
{
     public:
        NetworkServer();
        virtual bool establishConnection() = 0;
        string getPayloadKey();
        string getPayloadValue();
        void setPayloadKey(string key);
        void setPayloadValue(string value);

    protected:
        string payloadKey;
        string payloadValue;

    private:

};

#endif // NETWORKSERVER_H
