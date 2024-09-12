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
  event_handler* manufacture_failed;
  event_handler* order_received;
  event_handler* shipment_arrived;
  event_handler* shipment_lost;
  event_handler* manufacture_completed;
  event_handler* valid_payment;
  event_handler* invalid_payment;

  // Actions (Entry and Exit)
  action* start_warranty;
  action* refund;
  action* charge_client;
  action* dispatch_factory_lines;
  action* shutdown_factory_lines;
  action* get_order_size;
  action* reset_attempts;
  action* get_payment_method;
  action* increment_attempts;
  action* payment_rejected;
  action* update_stats;
  action* get_address;

  // Entry and Exit actions
  action* entry_to;
  action* exit_from;
};

#endif
