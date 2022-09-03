#include "SocketConnection.h"
#include "NetworkClient.h"
#include <iostream>
#include <string>
#include <utility>
#include "../../web-socket/easy-socket-master/include/masesk/EasySocket.hpp"
#define CLIENT_CHANNEL "117"
#define CLIENT_ID "117"
#define CLIENT_PORT 8030
#define CLIENT_IP "127.0.0.1"

using namespace std;
using namespace masesk;

SocketConnection *SocketConnection::instance = nullptr;

SocketConnection::SocketConnection(){
    channel = CLIENT_CHANNEL;
    socketPort = CLIENT_PORT;
    socketIp = CLIENT_IP;
}

static void handleData(string &payloadData, const string &data) {
    payloadData = data;
}

string SocketConnection::getServerChannel(){ return serverChannel;}
string SocketConnection::getServerIp(){ return serverIp;}
int SocketConnection::getServerPort(){ return serverPort;}

void SocketConnection::setServerChannel(string channel){ this->serverChannel = channel;}
void SocketConnection::setServerIp(string ip){ this->serverIp = ip;}
void SocketConnection::setServerPort(int port){ this->serverPort = port;}

SocketConnection* SocketConnection::getInestance(){
    if(!instance){
        instance = new SocketConnection();
    }
    return instance;
}

bool SocketConnection::establishConnection(){
    EasySocket socketManager;
    try{
        socketManager.socketConnect(serverChannel, serverIp, serverPort);
        socketManager.socketSend(serverChannel, channel+","+ socketIp +":" + to_string(socketPort));
        socketManager.closeConnection(serverChannel);
        return true;
    }catch (string error){
        return false;
    }catch(...){
        return false;
    }
}

bool SocketConnection::serverResponse(){
    EasySocket socketManager;
    try{
        string payloadData = "";
        socketManager.socketListen(channel, socketPort, &handleData, payloadData);
        parseNetworkData(payloadData);
        return true;
    }catch (string error){
        return false;
    }catch(...){
        return false;
    }
}

void SocketConnection::parseNetworkData(string payloadData){
    map<string,string> payload;
    string delim = ",";
    string keyValyDelim = ":";
    payloadData = payloadData.append(",");

    size_t pos = 0;
    string tempString; // define a string variable

    while (( pos = payloadData.find (delim)) != std::string::npos)  {
        tempString = payloadData.substr(0, pos); // store the substring
        int delimLocation = payloadData.find(keyValyDelim);
        payload.insert({tempString.substr(0, delimLocation), tempString.substr(delimLocation + 1, tempString.length())});
        //cout << tempString << endl;
        payloadData.erase(0, pos + delim.length());
    }
    setPayload(payload);
}

