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
        virtual map<string,string> parsePayloadToMap(string delimiter, string rawData);
        virtual pair<string,string> parsePayloadToPair(string delimiter, string rawData);
        virtual vector<string> parsePayloadToVector(string delimiter, string rawData);

    protected:

    private:
};

#endif // RAWDATAPARSER_H
