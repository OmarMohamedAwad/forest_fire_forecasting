#include "NetworkServer.h"
#include "SocketConnection.h"
#include <iostream>

   NetworkServer::NetworkServer(){
   }

   float NetworkServer::getPayload() {
      return payload;
   }

   void NetworkServer::setPayload(float payload) {
        this->payload = payload;
   }
