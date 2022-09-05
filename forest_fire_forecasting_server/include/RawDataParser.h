#ifndef RAWDATAPARSER_H
#define RAWDATAPARSER_H

#include <utility>
#include <map>
#include <string>
#include <vector>
#include "IParser.h"

using namespace std;

class RawDataParser : public IParser
{
    public:
        RawDataParser();
        map<string,string> parseRawDataToMap(string delimiter, string rawData);
        pair<string,string> parseRawDataToPair(string delimiter, string rawData);
        vector<string> parseRawDataToVector(string delimiter, string rawData);

    protected:

    private:
};

#endif // RAWDATAPARSER_H
