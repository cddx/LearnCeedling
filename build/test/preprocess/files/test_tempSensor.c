#include "build/temp/_test_tempSensor.c"
#include "mock_i2c.h"
#include "src/tempSensor.h"
#include "D:/LearnCeedling/vendor/ceedling/vendor/unity/src/unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}

void test_TempRegisterReadsMaxValue_TheTempIstheMaxValue(void)

{

    uint8_t tempRegisterAddress = 0x03;

    float expectedTemperature = 104.6f;

    float tolerance = 0.1f;





    i2c_readRegister_CMockExpectAndReturn(20, tempRegisterAddress, 0x3ff);





    float actualTemperature = tempSensor_getTemperature();

    UnityAssertFloatsWithin((UNITY_FLOAT)((tolerance)), (UNITY_FLOAT)((expectedTemperature)), (UNITY_FLOAT)((actualTemperature)), (

   ((void *)0)

   ), (UNITY_UINT)(24));

}

void test_TempRegisterReadsMinValue_TheTempIstheMinValue(void)

{

    uint8_t tempRegisterAddress = 0x03;

    float expectedTemperature = -100.0f;

    float tolerance = 0.1f;





    i2c_readRegister_CMockExpectAndReturn(33, tempRegisterAddress, 0x0);





    float actualTemperature = tempSensor_getTemperature();

    UnityAssertFloatsWithin((UNITY_FLOAT)((tolerance)), (UNITY_FLOAT)((expectedTemperature)), (UNITY_FLOAT)((actualTemperature)), (

   ((void *)0)

   ), (UNITY_UINT)(37));

}
