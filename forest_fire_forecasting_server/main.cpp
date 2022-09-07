#include <iostream>
#include "limits.h"
#include "./include/TemperatureSensor.h"
#include "./include/NetworkServer.h"
#include "./include/SocketConnection.h"
#include "./include/IParser.h"
#include "./include/RawDataParser.h"
#include <map>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <utility>
#include <gtest/gtest.h>
#define SERIAL_NUMBER "29.88.67.11"
#define TEST_OR_BUILD 0// 1 for Test - 0 for build

using namespace std;

std::condition_variable cv;


int main(int argc, char **argv)
{
    #if TEST_OR_BUILD == 1
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    #else
    map<string, string> clientsData;
    int x = 2;
    TemperatureSensor temperatureSensor = TemperatureSensor();
    SocketConnection* socketConnection = socketConnection->getInestance();
    IParser* parser = new RawDataParser();

    thread sendDataToClientsThread([&]() {
        float temp;
        string payload;
        mutex mtx;
        unique_lock<mutex> lck(mtx);

        while(true){
            temp = temperatureSensor.getTemperature();
            // TODO: Payload Formater
            payload = "Serial:";
            payload = payload.append(SERIAL_NUMBER).append(",Temperature:").append(to_string(temp));

            cout << "Waitting for New Clients" << endl;
            for (auto it = clientsData.cbegin(); it != clientsData.cend(); ){
                pair<string,string> parsedElement = parser->parsePayloadToPair(":",it->second);
                if(socketConnection->sendPayload(4, it->first, parsedElement.first, parsedElement.second, payload))
                    ++it;
                else
                    clientsData.erase(it++);
            }
            cv.wait_for(lck,chrono::seconds(1));
        }

    });

    thread setTemperaturePeriodically(&TemperatureSensor::setTemperaturePeriodically, &temperatureSensor);

    while(true){
        if(socketConnection->establishConnection()){
            pair<string, string> socketDataPair =  parser->parsePayloadToPair(",", socketConnection->getData());
            clientsData.insert({socketDataPair.first, socketDataPair.second});
        }
    }

    setTemperaturePeriodically.join();
    sendDataToClientsThread.join();
    #endif // TEST_OR_BUILD
}
