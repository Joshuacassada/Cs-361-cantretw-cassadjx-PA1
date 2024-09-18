//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/2024
// Author : Joshua Cassada and Thomas Cantrell
// File Name : statemodel.h
//---------------------------------------------------------------------
#ifndef statemodel_h
#define statemodel_h

#include <stdlib.h>
#include "system.h"
#include "state.h"

extern state_t accepting;
extern state_t processing;
extern state_t manufacturing;
extern state_t shipping;

void printStateName(void);
void handle_event( statsSetting current_event );

#endif