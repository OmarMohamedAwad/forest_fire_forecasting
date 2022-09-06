#ifndef TEMPERATURENODE_H
#define TEMPERATURENODE_H
#define READING_COUNT 5
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class TemperatureNode
{
    public:
        public:
        TemperatureNode();
        float getTemperature();
        float getAverageTemperature();
        void setTemperature(float newTemperaturReading);
        void updateNodeTemperatureArray();
        void calculateAverageTemperature();
        string getTempertureNodeId();
        void setTempertureNodeId(string nodeId);
        void setTempertureTimestamp();
        tm getTempertureTimestamp();

    protected:

    private:
        float celsiusTemperature;
        float celsiusTemperatureArray[READING_COUNT];
        int currentReadingIndex;
        float averageTemperature;
        string temperatureNodeId;
        tm temperatureTimeStamp;
};

#endif // TEMPERATURENODE_H
