#include "../include/TemperatureSensor.h"

    TemperatureSensor::TemperatureSensor(){
        temperatureCounter = 0;
        celsiusTemperature = 0.0;
    }

    float TemperatureSensor::getTemperature(){
        return celsiusTemperature;
    }

    void TemperatureSensor::setTemperature(float newTemperaturReading){
        this->celsiusTemperature = newTemperaturReading;
    }

    float TemperatureSensor::generateTemperature(int minReng, int maxReng){
        return minReng + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(maxReng-minReng)));
    }

    void TemperatureSensor::setTemperaturePeriodically(){
        condition_variable cv;

        float newTemp;
        mutex mtx;
        unique_lock<mutex> lck(mtx);

        while(true){
            newTemp = generateTemperature(30,40);
            setTemperature(newTemp);
            cv.wait_for(lck,chrono::seconds(1));
        }
    }
