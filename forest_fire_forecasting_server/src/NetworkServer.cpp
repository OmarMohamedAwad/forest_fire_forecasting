#include "NetworkServer.h"
#include <iostream>

   NetworkServer::NetworkServer(){
   }

   string NetworkServer::getPayloadKey() {
      return payloadKey;
   }

   string NetworkServer::getPayloadValue() {
      return payloadValue;
   }

   void NetworkServer::setPayloadKey(string key) {
        this->payloadKey = key;
   }

   void NetworkServer::setPayloadValue(string value) {
        this->payloadValue = value;
   }
