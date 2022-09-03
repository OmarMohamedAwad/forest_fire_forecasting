#include "TemperatureSensor.h"
#include "limits.h"
#include <cstdlib>
#include <iostream>

    TemperatureSensor::TemperatureSensor(){
        temperatureCounter = 0;
        celsiusTemperature = 0.0;
    }

    float TemperatureSensor::getTemperature(){
        return celsiusTemperature;
    }

    void TemperatureSensor::setTemperature(float newTemperaturReading){
        if (temperatureCounter == INT_MAX){
            celsiusTemperature = (newTemperaturReading + (celsiusTemperature)) /  2;
            temperatureCounter = 2;
        }else{
            celsiusTemperature = (newTemperaturReading + (static_cast<long>(temperatureCounter) * celsiusTemperature)) / (temperatureCounter + 1);
            temperatureCounter++;
        }

    }
