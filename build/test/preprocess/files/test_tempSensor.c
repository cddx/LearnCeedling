#include "build/temp/_test_tempSensor.c"
#include "build/test/mocks/mock_i2c.h"
#include "src/tempSensor.h"
#include "D:/LearnCeedling/vendor/ceedling/vendor/unity/src/unity.h"


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





    i2c_readRegister_CMockExpectAndReturn(20, tempRegisterAddress, 0x3ff);





    float actualTemperature = tempSensor_getTemperature();

    UnityAssertFloatsWithin((UNITY_FLOAT)((tolerance)), (UNITY_FLOAT)((expectedTemperature)), (UNITY_FLOAT)((actualTemperature)), (

   ((void *)0)

   ), (UNITY_UINT)(24));

}

void test_WhenTempRegisterReadsMinValue_ThenTheTempIstheMinValue(void)

{



    float expectedTemperature = -100.0f;

    float tolerance = 0.1f;





    i2c_readRegister_CMockExpectAndReturn(33, tempRegisterAddress, 0x0);





    float actualTemperature = tempSensor_getTemperature();

    UnityAssertFloatsWithin((UNITY_FLOAT)((tolerance)), (UNITY_FLOAT)((expectedTemperature)), (UNITY_FLOAT)((actualTemperature)), (

   ((void *)0)

   ), (UNITY_UINT)(37));

}

void test_WhenTempRegisterReads500_ThenTheTempIstheZero(void)

{



    float expectedTemperature = 0.0f;

    float tolerance = 0.1f;





    i2c_readRegister_CMockExpectAndReturn(46, tempRegisterAddress, 500);





    float actualTemperature = tempSensor_getTemperature();

    UnityAssertFloatsWithin((UNITY_FLOAT)((tolerance)), (UNITY_FLOAT)((expectedTemperature)), (UNITY_FLOAT)((actualTemperature)), (

   ((void *)0)

   ), (UNITY_UINT)(50));

}
