#ifndef TEMPERATURESENSOR_H
#define TEMPERATURESENSOR_H


class TemperatureSensor
{
     public:
        TemperatureSensor();
        float getTemperature();
        void setTemperature(float newTemperaturReading);
    protected:

    private:
        float celsiusTemperature;
        int temperatureCounter;
};

#endif // TEMPERATURESENSOR_H
