#include "SocketConnection.h"
#include "NetworkServer.h"
#include <iostream>

using namespace std;

SocketConnection *SocketConnection::instance = nullptr;

SocketConnection::SocketConnection()
{
    //ctor
}

SocketConnection* SocketConnection::getInestance(){
    if(!instance){
        instance = new SocketConnection();
    }
    return instance;
}

bool SocketConnection::establishConnection(){
    return true;
}
