#include <iostream>
#include "limits.h"
#include "TemperatureSensor.h"
#include "NetworkServer.h"


float generateRandomNumber(int minReng, int maxReng){
    return minReng + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxReng-minReng)));
}

int main()
{
    TemperatureSensor temperatureSensor = TemperatureSensor();
    NetworkServer* network = network->getInestance();

    std::cout << network->getPayload() << std::endl;
}


