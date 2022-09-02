#ifndef NETWORKSERVER_H
#define NETWORKSERVER_H


class NetworkServer
{
     public:
        static NetworkServer* getInestance();
        float getPayload();
        void setPayload(float payload);

    protected:

    private:
        NetworkServer();
        static NetworkServer *instance;
        float payload;
};

#endif // NETWORKSERVER_H
