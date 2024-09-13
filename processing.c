#include "processing.h"
#include "system.h"
#include "statemodel.h" 
#include <stdio.h>

// Declare the default event handler and the default action. 
// They are extern because they are used in each
// of the individual state files but defined in state.c.
extern state_t *default_event_handler();
extern void default_action();

state_t processing = {
    default_event_handler,
    invalid_payment,
    valid_payment,
    default_event_handler,
    default_event_handler,
    default_event_handler,
    default_event_handler,

    get_payment_method,
    default_action,
    default_action,
    default_action,
    entry_to,
    default_action
};

state_t* invalid_payment()
{
    incrementAttempts();
    if (payAttempts >= 3){
        paymentRejected();
        return &accepting;
    }
    else{
        return &processing;
    }
}

state_t* valid_payment()
{
    return &manufacturing;
}

static void entry_to()
{
    get_payment_method();
}

static void get_payment_method()
{
    printf("Get payment method");
}