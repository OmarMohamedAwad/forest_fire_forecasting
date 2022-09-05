#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H
#include "limits.h"
#include <cstdlib>
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>

using namespace std;

class TemperatureSensor
{
     public:
        TemperatureSensor();
        float getTemperature();
        void setTemperature(float newTemperaturReading);
        float generateTemperature(int minReng, int maxReng);
        void setTemperaturePeriodically();

    protected:

    private:
        float celsiusTemperature;
        int temperatureCounter;
};

#endif // TEMPERATURESENSOR_H
