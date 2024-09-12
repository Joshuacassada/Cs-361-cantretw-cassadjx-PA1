#ifndef shipping_h
#define shipping_h

#include "state.h"

static state_t*  shipment_lost();
static state_t*  shipment_arrived();
static void      start_warranty();
static void      refund();
static void      update_stats();
static void      entry_to_shipping();
static void      exit_from_shipping();


#endif