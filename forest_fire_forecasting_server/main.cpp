#include <iostream>
#include "limits.h"
#include "TemperatureSensor.h"
#include "NetworkServer.h"
#include "SocketConnection.h"
#include "IParser.h"
#include "RawDataParser.h"
#include <map>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <utility>
#include <gtest/gtest.h>
#define SERIAL_NUMBER "29.88.67.12"

using namespace std;

std::condition_variable cv;


pair<string,string> parseNetworkElement(string networkData);


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    map<string, string> clientsData;

    TemperatureSensor temperatureSensor = TemperatureSensor();
    SocketConnection* socketConnection = socketConnection->getInestance();
    RawDataParser* parser = new RawDataParser();

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

            cout << "in while" << endl;
            for (auto it = clientsData.cbegin(); it != clientsData.cend(); ){
                pair<string,string> parsedElement = parser->parseRawDataToPair(":",it->second);
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
            pair<string, string> socketDataPair =  parser->parseRawDataToPair(",", socketConnection->getData());
            clientsData.insert({socketDataPair.first, socketDataPair.second});
        }
    }

    setTemperaturePeriodically.join();
    sendDataToClientsThread.join();

    return RUN_ALL_TESTS();
}

pair<string,string> parseNetworkElement(string networkData) {
    string delim = ":";
    int delimLocation = networkData.find (delim);

    pair<string,string> networkDataPair;

    networkDataPair.first = networkData.substr(0, delimLocation);
    networkDataPair.second = networkData.substr(delimLocation + 1, networkData.length());

    return networkDataPair;
}
