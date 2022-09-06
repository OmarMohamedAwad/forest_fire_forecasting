#include "RawDataParser.h"

RawDataParser::RawDataParser()
{
    //ctor
}


map<string,string> RawDataParser::parsePayloadToMap(string delimiter, string keyValueDelimiter, string rawData){

    map<string,string> parsedMap;
    string delim = delimiter;
    string keyValyDelim = keyValueDelimiter;
    rawData = rawData.append(",");

    size_t pos = 0;
    string tempString;

    while (( pos = rawData.find (delim)) != std::string::npos)  {
        tempString = rawData.substr(0, pos); // store the substring
        int delimLocation = rawData.find(keyValyDelim);
        parsedMap.insert({tempString.substr(0, delimLocation), tempString.substr(delimLocation + 1, tempString.length())});
        rawData.erase(0, pos + delim.length());
    }

    return parsedMap;
}

pair<string,string> RawDataParser::parsePayloadToPair(string delimiter, string rawData){
    pair<string,string> parsedPair;
    string delim = delimiter;
    int delimLocation = rawData.find(delim);

    parsedPair.first = rawData.substr(0, delimLocation);
    parsedPair.second = rawData.substr(delimLocation + 1, rawData.length());

    return parsedPair;
}

vector<string> RawDataParser::parsePayloadToVector(string delimiter, string rawData){

}
