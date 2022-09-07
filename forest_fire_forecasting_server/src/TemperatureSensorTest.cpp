#include "../include/TemperatureSensorTest.h"

TemperatureSensorTest::TemperatureSensorTest()
{
}


TEST(GenerateTemperature, PositiveGenerateTemperature) {
    TemperatureSensor temperatureSensor = TemperatureSensor();
    float minVal = 30;
    float maxVal = 40;
    float generateTemp = temperatureSensor.generateTemperature(minVal, maxVal);
    EXPECT_GE(generateTemp, minVal);
    EXPECT_LE(generateTemp, maxVal);
}

TEST(GenerateTemperature, NegativeGenerateTemperature) {
    TemperatureSensor temperatureSensor = TemperatureSensor();
    float minVal = 30;
    float maxVal = 40;
    float generateTemp = temperatureSensor.generateTemperature(minVal - 20, maxVal + 20);
    EXPECT_GE(generateTemp, minVal);
}
