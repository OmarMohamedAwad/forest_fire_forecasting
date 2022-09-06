#include "SocketConnection.h"
#include "../../web-socket/easy-socket-master/include/masesk/EasySocket.hpp"
#define CLIENT_CHANNEL "118"
#define CLIENT_ID "118"
#define CLIENT_PORT 8040
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

//TODO
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
        cout << "catched establish issue" << endl;
        return false;
    }
}

bool SocketConnection::serverResponse(){
    EasySocket socketManager;
    try{
        string payloadData = "";
        socketManager.socketListen(channel, socketPort, &handleData, payloadData);
        setPayload(payloadData);
        return true;
    }catch (string error){
        return false;
    }catch(...){
        return false;
    }
}

void SocketConnection::handelConnection(string channel, string ip, int port) {
    condition_variable cv;
    unique_lock<mutex> lck(mtx);
    this->setServerChannel(channel);
    this->setServerIp(ip);
    this->setServerPort(port);

    int triersFlag = 0;
    while(triersFlag < 5){
        cout<< "Cooncting ...." << endl;
        if(!this->establishConnection()){
            cout<< "Retry to connect with server : " << ip << ":" << port<< endl;
            triersFlag++;
            cv.wait_for(lck,chrono::seconds(5));
        }else {
            cout<< "Cooncted to server : " << ip << ":" << port << endl;
            break;
        }
    }
    if(triersFlag == 5) cout << "The node with channel name : " << channel << " and ip with port : "<< ip << ":" << port << " is not available now" << endl;
}


