#include <stdint.h>
#include "unity.h"
#include "tempSensor.h"
#include "mock_i2c.h"

uint8_t tempRegisterAddress;
void setUp(void)
{
    tempRegisterAddress = 0x03;
}
void tearDown(void)
{
}
void test_WhenTempRegisterReadsMaxValue_ThenTheTempIstheMaxValue(void)
{
    float expectedTemperature = 104.6f;
    float tolerance = 0.1f;

    // When
    i2c_readRegister_ExpectAndReturn(tempRegisterAddress, 0x3ff);

    // Then
    float actualTemperature = tempSensor_getTemperature();
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature, actualTemperature);
}
void test_WhenTempRegisterReadsMinValue_ThenTheTempIstheMinValue(void)
{

    float expectedTemperature = -100.0f;
    float tolerance = 0.1f;

    // When
    i2c_readRegister_ExpectAndReturn(tempRegisterAddress, 0x0);

    // Then
    float actualTemperature = tempSensor_getTemperature();
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature, actualTemperature);
}
void test_WhenTempRegisterReads500_ThenTheTempIstheZero(void)
{

    float expectedTemperature = 0.0f;
    float tolerance = 0.1f;

    // When
    i2c_readRegister_ExpectAndReturn(tempRegisterAddress, 500);

    // Then
    float actualTemperature = tempSensor_getTemperature();
    TEST_ASSERT_FLOAT_WITHIN(tolerance, expectedTemperature, actualTemperature);
}