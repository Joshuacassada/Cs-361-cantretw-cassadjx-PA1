//---------------------------------------------------------------------
// Assignment : eBuild Term Project / Phase 1
// Date : 9/18/2024
// Author : Joshua Cassada and Thomas Cantrell
// File Name : driver.c
//---------------------------------------------------------------------
#include "statemodel.h"
#include "state.h"
#include <stdio.h>

state_t* current_state = &accepting;

int main(void) {
    events current_event;
    int key;

    // Print the initial state (if necessary)
    printStateName();
    current_state->entry_to();

    // Main event loop
    while ((key = getchar()) != EOF) {
        if (key == '\n') continue;  // Ignore newlines

        current_event = INVALID_EVENT;  // Default to invalid event

        // Map character inputs to the corresponding events
        switch (key) {
            case 'O':
                current_event = ORDER_RECEIVED;
                puts("Event: ORDER_RECEIVED");
                break;
            case 'V':
                current_event = VALID_PAYMENT;
                puts("Event: VALID_PAYMENT");
                break;
            case 'I':
                current_event = INVALID_PAYMENT;
                puts("Event: INVALID_PAYMENT");
                break;
            case 'F':
                current_event = MANUFACTURE_FAILED;
                puts("Event: MANUFACTURE_FAILED");
                break;
            case 'C':
                current_event = MANUFACTURE_COMPLETED;
                puts("Event: MANUFACTURE_COMPLETED");
                break;
            case 'R':
                current_event = SHIPMENT_ARRIVED;
                puts("Event: SHIPMENT_ARRIVED");
                break;
            case 'L':
                current_event = SHIPMENT_LOST;
                puts("Event: SHIPMENT_LOST");
                break;
            case 'X':
                printf("\n");
                exit(0);
            default:
                puts("Event: INVALID_EVENT");
        }

        if (current_event != INVALID_EVENT) {
            handle_event(current_event);
        }
    }

    printf("\n");
    fflush(stdout);
    return 0;
}