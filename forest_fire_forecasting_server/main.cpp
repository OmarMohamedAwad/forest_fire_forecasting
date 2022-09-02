#include <iostream>
#include "limits.h"
#include "TemperatureSensor.h"
#include "NetworkServer.h"
#include "SocketConnection.h"


float generateRandomNumber(int minReng, int maxReng){
    return minReng + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxReng-minReng)));
}

int main()
{
    std::cout<< "ay haga" << std::endl;

    TemperatureSensor temperatureSensor = TemperatureSensor();
    std::cout<< "ay haga 2" << std::endl;
    //NetworkServer* network = network->getInestance("Socket");

    SocketConnection* socketConnection = socketConnection->getInestance();
    std::cout<< "ay haga 3" << std::endl;

    std::cout<< socketConnection->establishConnection() << std::endl;
    //std::cout << network->getPayload() << std::endl;
}


