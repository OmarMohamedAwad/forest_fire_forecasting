#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H

class NetworkServer
{
     public:
        NetworkServer();
        virtual bool establishConnection() = 0;
        float getPayload();
        void setPayload(float payload);

    protected:

    private:
        float payload;
};

#endif // NETWORKSERVER_H
