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

int main()
{
    vector<TemperatureNode> nodes;
    mutex mtx;

    SocketConnection *socketConnection = socketConnection->getInestance();
    socketConnection->setServerChannel("brodcast");
    socketConnection->setServerIp("127.0.0.1");
    socketConnection->setServerPort(8010);

    socketConnection->establishConnection();

    socketConnection->setServerChannel("brodcast2");
    socketConnection->setServerIp("127.0.0.1");
    socketConnection->setServerPort(8020);

    socketConnection->establishConnection();

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

    calculateTemperetureAvgThread.join();
    calculateAccumelatedTemperetureAvgThread.join();

    return 0;
}
