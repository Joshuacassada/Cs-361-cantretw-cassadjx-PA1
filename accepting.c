#include "accepting.h"
#include "system.h"
#include "statemodel.h" 

// Declare the default event handler and the default action. 
// They are extern because they are used in each
// of the individual state files but defined in state.c.
extern state_t *default_event_handler();
extern void default_action();

state_t accepting = {
    order_received,
    default_event_handler,
    default_event_handler,
    default_event_handler,
    default_event_handler,
    default_event_handler,
    default_event_handler,

    default_action,
    default_action,
    default_action,
    default_action,
    default_action,
    default_action
};

state_t* order_received()
{   
    getOrderSize();
    resetAttempts();
    return &processing;
}