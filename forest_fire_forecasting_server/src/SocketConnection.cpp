#include "SocketConnection.h"
#include "NetworkServer.h"
#include <iostream>
#include <string>
#include <utility>
#include "../../web-socket/easy-socket-master/include/masesk/EasySocket.hpp"


using namespace std;
using namespace masesk;

SocketConnection *SocketConnection::instance = nullptr;

SocketConnection::SocketConnection(){
    channel = "brodcast2";
    socketPort = 8020;
    socketIp = "127.0.0.1";
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
        parseNetworkData(handCheckData);
        return true;
    }catch (string error){
        return false;
    }catch(...){
        return false;
    }
}

void SocketConnection::parseNetworkData(string handCheckData){
    string delim = ",";
    int delimLocation = handCheckData.find(delim);
    setPayloadKey(handCheckData.substr(0, delimLocation));
    setPayloadValue(handCheckData.substr(delimLocation + 1, handCheckData.length()));
}
