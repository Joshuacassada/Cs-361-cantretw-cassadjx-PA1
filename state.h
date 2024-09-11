#ifndef state_h
#define state_h

// Add an alias for a type to the global name space.
typedef struct state    state_t ; 

// Add an alias for event handlers.
typedef      state_t *   event_handler(void);
 
// Add an alias for actions.
typedef      void        action(void);

// Define the format of a state struct.
struct state {
  event_handler*  manufacture_failed;
  event_handler*  order_received;
  event_handler*  shipment_arrived;
  event_handler*  shipment_lost;
  event_handler*  manufacture_completed;
  action*         startWarranty;
  action*         entry_to;
  action*         exit_from;
};


#endif


