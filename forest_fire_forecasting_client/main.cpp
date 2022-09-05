#include <iostream>
#include "TemperatureNode.h"
#include "NetworkClient.h"
#include "SocketConnection.h"
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

#define IDENTIFIRE "Serial"
#define ATTRIBUTE "Temperature"

using namespace std;
std::condition_variable cv;

void nodeConnectionHandler(string channel, string ip, int port);

int main()
{
    vector<TemperatureNode> nodes;
    mutex mtx;
    SocketConnection *socketConnection = socketConnection->getInestance();

    thread nodeThread1(nodeConnectionHandler, "brodcast", "127.0.0.1", 8010);
    thread nodeThread2(nodeConnectionHandler, "brodcast2", "127.0.0.1", 8020);

    thread calculateTemperetureAvgThread([&]() {
        unique_lock<mutex> lck(mtx);

        while(true){
            int sizeOfNodes = nodes.size();
            for(int i = 0; i < sizeOfNodes; i++){
                nodes[i].calculateAverageTemperature();
                cout << "Avgrage of Node " << nodes[i].getTempertureNodeId() << " = "<< nodes[i].getAverageTemperature() << endl;
            }
            cv.wait_for(lck,chrono::seconds(5));
        }

    });

    thread calculateAccumelatedTemperetureAvgThread([&]() {
        float accumulatedAverage = 0.0;
        unique_lock<mutex> lck(mtx);

        while(true){
            accumulatedAverage = TemperatureNode::calculateAccumelatedTemperatureAverages(nodes);
            cout << "Accumulated Average of Nodes = " << accumulatedAverage << endl;
            cv.wait_for(lck,chrono::seconds(5));
        }

    });

    while(true){
        socketConnection->serverResponse();
        map<string, string> responsPayload = socketConnection->getPayload();
        string payloadIdentifire = responsPayload[IDENTIFIRE];
        bool isNodeFound = false;
        int sizeOfNodes = nodes.size();
        for(int i = 0; i < sizeOfNodes; i++){
            if(nodes[i].getTempertureNodeId() == payloadIdentifire){
                isNodeFound = true;
                nodes[i].setTemperature(atof(responsPayload[ATTRIBUTE].c_str()));
            }

        }

        if(!isNodeFound) {
            TemperatureNode newNode;
            newNode.setTempertureNodeId(responsPayload[IDENTIFIRE]);
            newNode.setTemperature(atof(responsPayload[ATTRIBUTE].c_str()));

            nodes.push_back(newNode);
        }
    }

    nodeThread1.join();
    nodeThread2.join();
    calculateTemperetureAvgThread.join();
    calculateAccumelatedTemperetureAvgThread.join();

    return 0;
}

void nodeConnectionHandler(string channel, string ip, int port) {
    mutex mtx;
    unique_lock<mutex> lck(mtx);
    SocketConnection *socketConnection = socketConnection->getInestance();
    socketConnection->setServerChannel(channel);
    socketConnection->setServerIp(ip);
    socketConnection->setServerPort(port);

    int triersFlag = 0;
    while(triersFlag < 5){
        if(!socketConnection->establishConnection()){
            triersFlag++;
            cv.wait_for(lck,chrono::seconds(5));
        }else break;
    }
    if(triersFlag == 5) cout << "The node with channel name : " << channel << " and ip with port : "<< ip << ":" << port << " is not available now" << endl;
}
