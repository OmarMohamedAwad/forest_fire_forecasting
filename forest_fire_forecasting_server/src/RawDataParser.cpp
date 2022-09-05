#include "RawDataParser.h"

RawDataParser::RawDataParser()
{
    //ctor
}


map<string,string> RawDataParser::parseRawDataToMap(string delimiter, string rawData){

}

pair<string,string> RawDataParser::parseRawDataToPair(string delimiter, string rawData){
    pair<string,string> parsedPair;
    string delim = delimiter;
    int delimLocation = rawData.find(delim);

    parsedPair.first = rawData.substr(0, delimLocation);
    parsedPair.second = rawData.substr(delimLocation + 1, rawData.length());

    return parsedPair;
}

vector<string> RawDataParser::parseRawDataToVector(string delimiter, string rawData){

}
