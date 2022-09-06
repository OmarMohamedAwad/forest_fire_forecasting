#ifndef APPLICATIONHELPER_H
#define APPLICATIONHELPER_H
#include <ctime>
#include <vector>
#include "TemperatureNode.h"

using namespace std;

class ApplicationHelper
{
    public:
        ApplicationHelper();
        static float calculateAccumelatedAverages(vector<TemperatureNode> &nodes);
        static bool comparTimestamp(tm timestamp);
    protected:

    private:
};

#endif // APPLICATIONHELPER_H
