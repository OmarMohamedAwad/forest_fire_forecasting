#include "RawDataParser.h"

RawDataParser::RawDataParser()
{
    //ctor
}


map<string,string> RawDataParser::parsePayloadToMap(string delimiter, string rawData){

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
