#ifndef manufacturing_h
#define manufacturing_h

#include "state.h"

static void      entry_to_manufacturing();
static void      exit_from_manufacturing();
static state_t*  manufacture_completed();
static state_t*  manufacture_failed();
static void      dispatchFactoryLines();
static void      shutDownFactoryLines();


#endif