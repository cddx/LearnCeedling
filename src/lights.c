#include <stdbool.h>
#include "lights.h"

static bool areLightsOn = false;
void lights_SetHeadlightSwitchOn(void)
{
    areLightsOn = true;
}
void lights_SetHeadlightSwitchOff(void)
{
    areLightsOn = false;
}
bool lights_AreHeadlightsOn(void)
{
    return areLightsOn;
}