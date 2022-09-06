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

        return totalSum / validNode;
    }

    bool ApplicationHelper::comparTimestamp(tm timestamp){
        time_t now = time(0);
        tm currentTimeStamp = *gmtime(&now);

        if(difftime(timegm(&currentTimeStamp), timegm(&timestamp)) > 15) return false;
        return true;
    }
