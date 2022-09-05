#ifndef RAWDATAPARSER_H
#define RAWDATAPARSER_H

#include <utility>
#include <string>
#include <vector>

using namespace std;

class rawDataParser : public IParser
{
    public:
        rawDataParser();
        map<string,string> parseRawDataToMap(string delimiter, string rawData);
        pair<string,string> parseRawDataToPair(string delimiter, string rawData);
        vector<string> parseRawDataToVector(string delimiter, string rawData);

    protected:

    private:
};

#endif // RAWDATAPARSER_H
