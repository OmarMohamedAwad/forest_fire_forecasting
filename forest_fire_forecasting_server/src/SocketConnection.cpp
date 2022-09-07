#include "../include/SocketConnection.h"
#define SERVER_CHANNEL "brodcast"
#define SERVER_PORT 8010
#define SERVER_IP "127.0.0.1"

using namespace masesk;

SocketConnection *SocketConnection::instance = nullptr;

SocketConnection::SocketConnection(){
    channel = SERVER_CHANNEL;
    socketPort = SERVER_PORT;
    socketIp = SERVER_IP;
}

static void handleData(string &handCheckData, const string &data) {
    handCheckData = data;
}

SocketConnection* SocketConnection::getInestance(){
    if(!instance){
        instance = new SocketConnection();
    }
    return instance;
}

bool SocketConnection::establishConnection(){
    EasySocket socketManager;
    string handCheckData = "";
    try{
        socketManager.socketListen(channel, socketPort, &handleData, handCheckData);
        setData(handCheckData);
        return true;
    }catch (string error){
        return false;
    }catch(...){
        return false;
    }
}

bool SocketConnection::sendPayload(int count, ...){

    va_list list;
    va_start(list, count);

    string clientChannel, clientIp, clientPort, clientPayload;

    EasySocket socketManager;
    try{
        if(count == 4){
            clientChannel = va_arg(list, string);
            clientIp = va_arg(list, string);
            clientPort = va_arg(list, string);
            clientPayload = va_arg(list, string);
        }
        va_end(list);

        socketManager.socketConnect(clientChannel, clientIp, stoi(clientPort));
        socketManager.socketSend(clientChannel, clientPayload);
        socketManager.closeConnection(clientChannel);
        return true;
    }catch (...){
        socketManager.closeConnection(clientChannel);
        return false;
    }
}
