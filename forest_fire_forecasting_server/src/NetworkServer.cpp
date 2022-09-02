#include "NetworkServer.h"

   NetworkServer *NetworkServer::instance = nullptr;

   NetworkServer::NetworkServer() {
      payload = 0;
   }

    NetworkServer* NetworkServer::getInestance() {
      if (!instance)
        instance = new NetworkServer;
      return instance;
   }

   float NetworkServer::getPayload() {
      return payload;
   }

   void NetworkServer::setPayload(float payload) {
        this->payload = payload;
   }
