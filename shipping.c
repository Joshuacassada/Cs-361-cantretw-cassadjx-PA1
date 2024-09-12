#include "shipping.h"
#include "system.h"
#include "statemodel.h" // For the other states

// Declare the default event handler and the default action. 
// They are extern because they are used in each
// of the individual state files but defined in state.c.
extern state_t *  default_event_handler();
extern void       default_action();

state_t shipping = {
    default_event_handler,
    default_event_handler,
    default_event_handler, 
    default_event_handler,
    default_event_handler,
    shipment_lost,
    shipment_arrived,

    // Actions (Entry and Exit)
    default_action, 
    default_action, 
    default_action,
    default_action, 
    default_action, 
    default_action, 
    default_action, 
    refund,
    update_stats,
    default_action,
    default_action,   
    start_warranty,

    // Entry and Exit actions
    entry_to_shipping,
    exit_from_shipping,
};

state_t*  shipment_lost()
{
    refund();
    return &accepting;
}
state_t*  shipment_arrived()
{
    start_warranty();
    update_stats(DONE);
    return &accepting;
}
void start_warranty()
{
    
}
void refund()
{
    update_stats(LOST);
}
void update_stats()
{

}
void entry_to_shipping()
{

}
void exit_from_shipping()
{
    update_stats(DONE);
}