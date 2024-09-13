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
                puts("Event: Order received");
                break;
            case 'V':
                current_event = VALID_PAYMENT;
                puts("Event: Payment validated");
                break;
            case 'I':
                current_event = INVALID_PAYMENT;
                puts("Event: Payment rejected");
                break;
            case 'F':
                current_event = MANUFACTURE_FAILED;
                puts("Event: Factory failed");
                break;
            case 'C':
                current_event = MANUFACTURE_COMPLETED;
                puts("Event: Factory success");
                break;
            case 'R':
                current_event = SHIPMENT_ARRIVED;
                puts("Event: Shipment confirmed");
                break;
            case 'L':
                current_event = SHIPMENT_LOST;
                puts("Event: Shipment failed");
                break;
            case 'X':
                current_event = INVALID_EVENT;
                puts("Event: Terminate program");
                break;
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