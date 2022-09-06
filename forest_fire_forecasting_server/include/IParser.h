#ifndef IPARSER_H
#define IPARSER_H

#include <utility>
#include <map>
#include <string>
#include <vector>

using namespace std;

class IParser
{
    public:
        IParser();
        virtual map<string,string> parsePayloadToMap(string delimiter, string rawData) = 0;
        virtual pair<string,string> parsePayloadToPair(string delimiter, string rawData) = 0;
        virtual vector<string> parsePayloadToVector(string delimiter, string rawData) = 0;

    protected:

    private:
};

#endif // IPARSER_H
