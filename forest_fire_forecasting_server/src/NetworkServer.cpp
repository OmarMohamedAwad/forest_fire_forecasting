#include "NetworkServer.h"
#include "SocketConnection.h"
#include <iostream>

   // NetworkServer *NetworkServer::instance = nullptr;

   NetworkServer::NetworkServer(){
        std::cout << "NetworkServer"<< std::endl;
   }

   float NetworkServer::getPayload() {
      return payload;
   }

   void NetworkServer::setPayload(float payload) {
        this->payload = payload;
   }
