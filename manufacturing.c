#include "stdio.h"
#include "manufacturing.h"
#include "system.h"
#include "statemodel.h" 

// Declare the default event handler and the default action. 
// They are extern because they are used in each
// of the individual state files but defined in state.c.
extern state_t *default_event_handler();
extern void default_action();

state_t manufacturing = {
    default_event_handler,
    default_event_handler,
    default_event_handler,
    manufacture_completed,
    manufacture_failed,
    default_event_handler,
    default_event_handler,

    default_action,
    dispatchFactoryLines,
    shutDownFactoryLines,
    default_action,
    entry_to_manufacturing,
    exit_from_manufacturing
};
static void dispatchFactoryLines()
{
    printf("Dispatching Factory Lines");
}
static void shutDownFactoryLines()
{
    printf("Shutting Down Factory Lines");
}
static void entry_to_manufacturing()
{
    dispatchFactoryLines();
}
static void exit_from_manufacturing()
{
    shutDownFactoryLines();
}
state_t*  manufacture_completed()
{
    exit_from_manufacturing();
    chargeClient();
}
state_t*  manufacture_failed()
{
    exit_from_manufacturing();
    updateStats(FAIL);
    return &accepting;
}
