#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H
#include <map>
#include <string>

using namespace std;

class NetworkClient
{
     public:
        NetworkClient();
        virtual bool establishConnection() = 0;
        map<string,string> getPayload();
        void setPayload(map<string,string> payload);

    protected:
        map<string,string> payload;

    private:
};

#endif // NETWORKCLIENT_H
