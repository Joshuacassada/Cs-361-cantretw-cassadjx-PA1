//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/2024
// Author : Joshua Cassada and Thomas Cantrell
// File Name : state.h
//---------------------------------------------------------------------
#ifndef state_h
#define state_h

// Add an alias for a type to the global name space.
typedef struct state state_t; 

// Add an alias for event handlers.
typedef state_t* event_handler(void);

// Add an alias for actions.
typedef void action(void);

// Define the format of a state struct.
struct state {
  // Event Handlers
  event_handler* order_received;
  event_handler* invalid_payment;
  event_handler* valid_payment;
  event_handler* manufacture_completed;
  event_handler* manufacture_failed;
  event_handler* shipment_lost; 
  event_handler* shipment_arrived;

  // Actions (Entry and Exit)
  action* get_payment_method;
  action* dispatch_factory_lines;
  action* shutdown_factory_lines;
  action* get_address;

  // Entry and Exit actions
  action* entry_to;
  action* exit_from;
};

#endif
