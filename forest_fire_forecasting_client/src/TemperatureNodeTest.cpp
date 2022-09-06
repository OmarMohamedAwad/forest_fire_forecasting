#include "TemperatureNodeTest.h"

TemperatureNodeTest::TemperatureNodeTest()
{
    //ctor
}

TEST(AverageTemprature, PositiveAvaregeTemperature) {
    TemperatureNode temperatureNode;
    temperatureNode.setTemperature(1);
    temperatureNode.setTemperature(2);
    temperatureNode.setTemperature(3);
    temperatureNode.setTemperature(4);
    temperatureNode.setTemperature(5);
    temperatureNode.calculateAverageTemperature();
    ASSERT_EQ(3, temperatureNode.getAverageTemperature());
}

TEST(AverageTemprature, NegativeAvaregeTemperature) {
    TemperatureNode temperatureNode;
    temperatureNode.setTemperature(1);
    temperatureNode.setTemperature(2);
    temperatureNode.setTemperature(3);
    temperatureNode.setTemperature(4);
    temperatureNode.setTemperature(5);
    temperatureNode.calculateAverageTemperature();
    ASSERT_EQ(6, temperatureNode.getAverageTemperature());
}

TEST(AccumelaredAverageTemprature, PositiveAccumelaredAvgTemperature) {
    vector<TemperatureNode> nodes;
    TemperatureNode temperatureNode;
    temperatureNode.setTemperature(1);
    temperatureNode.setTemperature(2);
    temperatureNode.setTemperature(3);
    temperatureNode.setTemperature(4);
    temperatureNode.setTemperature(5);
    temperatureNode.setTempertureTimestamp();
    temperatureNode.calculateAverageTemperature();
    nodes.push_back(temperatureNode);

    ASSERT_EQ(3, ApplicationHelper::calculateAccumelatedAverages(nodes));
}

TEST(AccumelaredAverageTemprature, PositiveAccumelaredTwoSensorAvgTemperature) {
    vector<TemperatureNode> nodes;
    TemperatureNode temperatureNode;
    temperatureNode.setTemperature(1);
    temperatureNode.setTemperature(2);
    temperatureNode.setTemperature(3);
    temperatureNode.setTemperature(4);
    temperatureNode.setTemperature(5);
    temperatureNode.setTempertureTimestamp();
    temperatureNode.calculateAverageTemperature();
    nodes.push_back(temperatureNode);
    TemperatureNode temperatureNode2;
    temperatureNode2.setTemperature(5);
    temperatureNode2.setTemperature(5);
    temperatureNode2.setTemperature(5);
    temperatureNode2.setTemperature(5);
    temperatureNode2.setTemperature(5);
    temperatureNode2.setTempertureTimestamp();
    temperatureNode2.calculateAverageTemperature();
    nodes.push_back(temperatureNode2);
    ASSERT_EQ(4, ApplicationHelper::calculateAccumelatedAverages(nodes));
}

TEST(AccumelaredAverageTemprature, PositiveAccumelaredNoNodsAvgTemperature) {
    vector<TemperatureNode> nodes;
    EXPECT_DOUBLE_EQ(0.0, ApplicationHelper::calculateAccumelatedAverages(nodes));
}

TEST(AccumelaredAverageTemprature, NegativeAccumelaredAvgTemperature) {
    vector<TemperatureNode> nodes;
    TemperatureNode temperatureNode;
    temperatureNode.setTemperature(1);
    temperatureNode.setTemperature(2);
    temperatureNode.setTemperature(3);
    temperatureNode.setTemperature(4);
    temperatureNode.setTemperature(5);
    temperatureNode.setTempertureTimestamp();
    temperatureNode.calculateAverageTemperature();
    nodes.push_back(temperatureNode);

    ASSERT_EQ(2, ApplicationHelper::calculateAccumelatedAverages(nodes));
}

TEST(TimestampTemprature, PositiveTimestampTemprature) {
    TemperatureNode temperatureNode;
    temperatureNode.setTempertureTimestamp();

    ASSERT_TRUE(ApplicationHelper::comparTimestamp(temperatureNode.getTempertureTimestamp()));
}

TEST(TimestampTemprature, NegatineTimestampTemprature) {
    time_t now = time(0);
    tm *currentTimeStamp = localtime(&now);
    --currentTimeStamp->tm_mday; // Move back one day
    mktime(currentTimeStamp); // Normalize

    asctime(currentTimeStamp);
    ASSERT_TRUE(ApplicationHelper::comparTimestamp(*currentTimeStamp));
}
