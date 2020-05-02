#include "unity.h"
#include "lights.h"

void setUp(void)
{
}
void tearDown(void)
{
}
void test_TheHeadlightSwitchIsOff_TheHeadLightsAreOff(void)
{
    // When the headlight switch is off...
    lights_SetHeadlightSwitchOff();

    // then the headlight are off
    TEST_ASSERT_EQUAL(true, lights_AreHeadlightsOn());
}
void test_TheHeadlightSwitchIsOn_TheHeadlightsAreOn(void)
{
    // When the headlight switchis on...
    lights_SetHeadlightSwitchOn();

    // then the headlights are on.
    TEST_ASSERT_EQUAL(true, lights_AreHeadlightsOn());
}