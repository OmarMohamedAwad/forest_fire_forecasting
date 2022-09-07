#include <iostream>
#include "./include/TemperatureNode.h"
#include "./include/NetworkClient.h"
#include "./include/SocketConnection.h"
#include "./include/IParser.h"
#include "./include/RawDataParser.h"
#include "./include/ApplicationHelper.h"
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <gtest/gtest.h>
#include <condition_variable>
#define TEST_OR_BUILD 0// 1 for Test - 0 for build


#define IDENTIFIRE "Serial"
#define ATTRIBUTE "Temperature"

using namespace std;
std::condition_variable cv;

int main(int argc, char **argv)
{

    #if TEST_OR_BUILD == 1
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    #else
    map<string, string> clientsData;
    vector<TemperatureNode> nodes;
    mutex mtx;
    IParser *parser = new RawDataParser();
    SocketConnection *socketConnection = socketConnection->getInestance();

    thread nodeThread1(&SocketConnection::handelConnection, socketConnection,"brodcast", "127.0.0.1", 8010);
    thread nodeThread2(&SocketConnection::handelConnection, socketConnection, "brodcast2", "127.0.0.1", 8020);

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
            accumulatedAverage = ApplicationHelper::calculateAccumelatedAverages(nodes);
            accumulatedAverage = accumulatedAverage > 0.0 ? accumulatedAverage : 0.0;
            cout << "Accumulated Average of Nodes = " << accumulatedAverage << endl;
            cv.wait_for(lck,chrono::seconds(5));
        }

    });

    while(true){
        socketConnection->serverResponse();
        map<string, string> responsPayload = parser->parsePayloadToMap(",", ":", socketConnection->getPayload());

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

    #endif // TEST_OR_BUILD

}

