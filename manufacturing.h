//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/2024
// Author : Joshua Cassada and Thomas Cantrell
// File Name : manufacturing.h
//---------------------------------------------------------------------
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