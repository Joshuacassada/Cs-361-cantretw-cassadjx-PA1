//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/2024
// Author : Joshua Cassada and Thomas Cantrell
// File Name : shipping.c
//---------------------------------------------------------------------
#include "shipping.h"
#include "stdio.h"
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
  
    // Entry and Exit actions
    entry_to_shipping,
    default_action
};


static void entry_to_shipping()
{
    printf("Getting Ship-To Address\n");
}
state_t* shipment_lost()
{
    refund();
    updateStats(LOST);
    return &accepting;
}
state_t* shipment_arrived()
{
    startWarranty();
    updateStats(DONE);
    return &accepting;
}

