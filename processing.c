#include "processing.h"
#include "system.h"
#include "statemodel.h" 

// Declare the default event handler and the default action. 
// They are extern because they are used in each
// of the individual state files but defined in state.c.
extern state_t *default_event_handler();
extern void default_action();

state_t accepting = {
    default_event_handler,
    invalid_payment,
    valid_payment,
    default_event_handler,
    default_event_handler,
    default_event_handler,
    default_event_handler,

    default_action,
    default_action,
    default_action,
    get_payment_method,
    incremental_attempts,
    default_action,
    default_action,
    default_action,
    default_action,
    default_action,
    default_action,
    entry_to,
    default_action
};

state_t* invalid_payment()
{
    
}

state_t* valid_payment()
{
    return &manufacturing;
}

