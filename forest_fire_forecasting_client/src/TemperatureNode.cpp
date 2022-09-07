#include "../include/TemperatureNode.h"
#include "limits.h"
#include <cstdlib>
#include <iostream>

using namespace std;

    TemperatureNode::TemperatureNode():celsiusTemperatureArray ({0}){
        currentReadingIndex = 0;
        celsiusTemperature = 0.0;
        averageTemperature = 0.0;
    }

    string TemperatureNode::getTempertureNodeId(){
        return temperatureNodeId;
    }


    void TemperatureNode::setTempertureNodeId(string nodeId){
        this->temperatureNodeId = nodeId;
    }

    float TemperatureNode::getTemperature(){
        return celsiusTemperature;
    }

    void TemperatureNode::setTemperature(float celsiusTemperature){
        this->celsiusTemperature = celsiusTemperature;
        setTempertureTimestamp();
        updateNodeTemperatureArray();
    }

    tm TemperatureNode::getTempertureTimestamp(){
        return temperatureTimeStamp;
    }

    void TemperatureNode::setTempertureTimestamp(){
        time_t now = time(0);
        this->temperatureTimeStamp = *gmtime(&now);
    }

    void TemperatureNode::updateNodeTemperatureArray(){
        if(currentReadingIndex == READING_COUNT)
            currentReadingIndex = 0;
        celsiusTemperatureArray[currentReadingIndex++] = celsiusTemperature;
    }

    float TemperatureNode::getAverageTemperature(){
        return averageTemperature;
    }

    void TemperatureNode::calculateAverageTemperature(){
        float totalSum = 0;
        for (float item : celsiusTemperatureArray)
            totalSum += item;

        averageTemperature = totalSum / READING_COUNT;
    }
