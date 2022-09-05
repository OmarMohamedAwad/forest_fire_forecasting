#include "NetworkServer.h"

   NetworkServer::NetworkServer(){
   }

   string NetworkServer::getData() {
      return payloadData;
   }

   void NetworkServer::setData(string data) {
        this->payloadData = data;
   }
