#include <iostream>
#include "limits.h"
#include "TemperatureSensor.h"
#include "NetworkServer.h"
#include "SocketConnection.h"
#include <map>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
#include <utility>
#include "../../web-socket/easy-socket-master/include/masesk/EasySocket.hpp"
#define SERIAL_NUMBER "29.88.67.12"

using namespace std;
using namespace masesk;

std::condition_variable cv;


pair<string,string> parseNetworkElement(string networkData);
float generateRandomNumber(int minReng, int maxReng);

int main()
{
    map<string, string> clientsData;

    TemperatureSensor temperatureSensor = TemperatureSensor();
    SocketConnection* socketConnection = socketConnection->getInestance();

    thread sendDataToClientsThread([&]() {
        float temp;
        string payload;
        mutex mtx;
        unique_lock<mutex> lck(mtx);

        EasySocket socketManager;
        while(true){
            temp = temperatureSensor.getTemperature();
            payload = "Serial:";
            payload = payload.append(SERIAL_NUMBER).append(",Temperature:").append(to_string(temp));

            cout << "in while" << endl;
            for (auto it = clientsData.cbegin(); it != clientsData.cend() /* not hoisted */; ){
                pair<string,string> parsedElement = parseNetworkElement(it->second);
                try{
                    socketManager.socketConnect(it->first, parsedElement.first, stoi(parsedElement.second));
                    socketManager.socketSend(it->first, payload);
                    socketManager.closeConnection(it->first);
                    ++it;
                }catch (...){
                    socketManager.closeConnection(it->first);
                    clientsData.erase(it++);
                }
            }
            cv.wait_for(lck,chrono::seconds(1));
        }

    });


    thread sendTemperature([&]() {
        float newTemp;
        mutex mtx;
        unique_lock<mutex> lck(mtx);

        while(true){
            newTemp = generateRandomNumber(30,40);
            temperatureSensor.setTemperature(newTemp);
            cv.wait_for(lck,chrono::seconds(1));
        }

    });


    while(true){
        if(socketConnection->establishConnection()){
            clientsData.insert({socketConnection->getPayloadKey(), socketConnection->getPayloadValue()});
        }
    }

    sendTemperature.join();
    sendDataToClientsThread.join();
}

pair<string,string> parseNetworkElement(string networkData) {
    string delim = ":";
    int delimLocation = networkData.find (delim);

    pair<string,string> networkDataPair;

    networkDataPair.first = networkData.substr(0, delimLocation);
    networkDataPair.second = networkData.substr(delimLocation + 1, networkData.length());

    return networkDataPair;
}

float generateRandomNumber(int minReng, int maxReng){
    return minReng + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxReng-minReng)));
}
