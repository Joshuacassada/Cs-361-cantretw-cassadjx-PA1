#ifndef shipping_h
#define shipping_h

#include "state.h"

static void      entry_to_shipping();
static state_t*  shipment_lost();
static state_t*  shipment_arrived();

#endif