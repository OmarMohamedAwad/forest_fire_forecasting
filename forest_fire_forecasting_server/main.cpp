#include <iostream>
#include "limits.h"
#include "TemperatureSensor.h"
#include "NetworkServer.h"
#include "SocketConnection.h"
#include <map>
#include <string>
#include <thread>
#include <chrono>
#include <condition_variable>
#include <utility>
#include "../../web-socket/easy-socket-master/include/masesk/EasySocket.hpp"
#include <mutex>

using namespace std;
using namespace masesk;

std::condition_variable cv;


pair<string,string> parseNetworkElement(string networkData);
float generateRandomNumber(int minReng, int maxReng);

int main()
{
    map<string, string> clientsData;

    TemperatureSensor temperatureSensor = TemperatureSensor();
    //NetworkServer* network = network->getInestance("Socket");

    SocketConnection* socketConnection = socketConnection->getInestance();

    thread sendDataToClientsThread([&]() {
        float temp;

        mutex mtx;
        unique_lock<mutex> lck(mtx);

        EasySocket socketManager;
        while(true){
            temp = temperatureSensor.getTemperature();
            cout << "in while" << endl;
            for (auto element :clientsData){
                pair<string,string> parsedElement = parseNetworkElement(element.second);
                socketManager.socketConnect(element.first, parsedElement.first, stoi(parsedElement.second));
                socketManager.socketSend(element.first, to_string(temp));
                socketManager.closeConnection(element.first);
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
            clientsData.insert({socketConnection->getKey(), socketConnection->getValue()});
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
