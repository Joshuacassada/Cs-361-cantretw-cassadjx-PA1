#ifndef processing_h
#define processing_h

#include "state.h"

static state_t* valid_payment();
static state_t* invalid_payment();
static void incremental_attempts();
static void entry_to();
static void get_payment_method();

#endif