#include "build/temp/_test_lights.c"
#include "src/lights.h"
#include "D:/LearnCeedling/vendor/ceedling/vendor/unity/src/unity.h"


void setUp(void)

{

}

void tearDown(void)

{

}

void test_TheHeadlightSwitchIsOff_TheHeadLightsAreOff(void)

{



    lights_SetHeadlightSwitchOff();





    UnityAssertEqualNumber((UNITY_INT)((

   1

   )), (UNITY_INT)((lights_AreHeadlightsOn())), (

   ((void *)0)

   ), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_INT);

}

void test_TheHeadlightSwitchIsOn_TheHeadlightsAreOn(void)

{



    lights_SetHeadlightSwitchOn();





    UnityAssertEqualNumber((UNITY_INT)((

   1

   )), (UNITY_INT)((lights_AreHeadlightsOn())), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

}
