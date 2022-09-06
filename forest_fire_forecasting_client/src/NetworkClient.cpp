#include "NetworkClient.h"


   NetworkClient::NetworkClient(){}

   string NetworkClient::getPayload() {
      return payload;
   }

   void NetworkClient::setPayload(string payload) {
      this->payload = payload;
   }
