//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/2024
// Author : Joshua Cassada and Thomas Cantrell
// File Name : shipping.h
//---------------------------------------------------------------------
#ifndef shipping_h
#define shipping_h

#include "state.h"

static void      entry_to_shipping();
static state_t*  shipment_lost();
static state_t*  shipment_arrived();

#endif