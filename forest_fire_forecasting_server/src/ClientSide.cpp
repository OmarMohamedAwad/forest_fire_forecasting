#include "ClientSide.h"
#include "/home/omar-awad/Desktop/Dell/easy-socket-master/include/masesk/EasySocket.hpp"
#include <iostream>

using namespace std;
using namespace masesk;

ClientSide::ClientSide()
{
    //ctor
}


void ClientSide::establishConnection(){
    cout << "client side" << endl;
    EasySocket socketManager;
	socketManager.socketConnect("test", "127.0.0.1", 8010);
	socketManager.socketSend("test", "Hello from client!");
	socketManager.closeConnection("test");

}
