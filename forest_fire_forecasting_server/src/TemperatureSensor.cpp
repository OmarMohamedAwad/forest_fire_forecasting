#include "TemperatureSensor.h"
#include "limits.h"
#include <cstdlib>

    TemperatureSensor::TemperatureSensor(){
        temperatureCounter = 0;
    }

    float TemperatureSensor::getTemperature(){
        return celsiusTemperature;
    }

    void TemperatureSensor::setTemperature(float newTemperaturReading){
        if (temperatureCounter == INT_MAX){
            celsiusTemperature = (newTemperaturReading + (celsiusTemperature)) /  2;
            temperatureCounter = 2;
        }else{
            celsiusTemperature = (newTemperaturReading + (temperatureCounter * celsiusTemperature)) / temperatureCounter + 1;
            temperatureCounter++;
        }
    }
