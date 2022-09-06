#include "ApplicationHelper.h"

    ApplicationHelper::ApplicationHelper()
    {
        //ctor
    }

    float ApplicationHelper::calculateAccumelatedAverages(vector<TemperatureNode> &nodes){
        float totalSum = 0;
        int validNode = 0;
        for (auto item : nodes){
            if(comparTimestamp(item.getTempertureTimestamp())){
                validNode++;
                totalSum += item.getAverageTemperature();
            }
        }
        float accumulatedAverage = (totalSum / validNode) > 0.0 ? (totalSum / validNode) : 0.0;
        return accumulatedAverage;
    }

    bool ApplicationHelper::comparTimestamp(tm timestamp){
        time_t now = time(0);
        tm currentTimeStamp = *gmtime(&now);

        if(difftime(timegm(&currentTimeStamp), timegm(&timestamp)) > 15) return false;
        return true;
    }
