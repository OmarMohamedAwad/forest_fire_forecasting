#include "NetworkClient.h"
#include <iostream>


   NetworkClient::NetworkClient(){}

   map<string, string> NetworkClient::getPayload() {
      return payload;
   }

   void NetworkClient::setPayload(map<string, string> payload) {
      this->payload = payload;
   }
