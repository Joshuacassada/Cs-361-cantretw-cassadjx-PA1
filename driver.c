#include "statemodel.h"
#include "state.h"
#include <stdio.h>

state_t* current_state = &accepting;

int main(void){
    statsSetting current_event;
    int key;

    printStateName();
    current_state->entry_to();

    while ((key=getchar()) != 'X'){
        if (key == '\n') continue;

        current_event = INVALID_EVENT;
        switch(key){
            case 'c':
                    current_event = CLOSE_BUTTON_PRESSED;
                    puts("Event: ClOSE_BUTTON_PRESSED");
                    break;
            case 'C':
                    current_event = CLOSED_DETECTED;
                    puts("Event: CLOSED_DETECTED");
                    break;
            case 'o':
                    current_event = OPEN_BUTTON_PRESSED;
                    puts("Event: OPEN_BUTTON_PRESSED");
                    break;
            case 'O':
                    current_event = OPENED_DETECTED;
                    puts("Event: OPENED_DETECTED");
                    break;
            case 'x':
                    exit(0);
            default:
                    puts("Event: INVALID_EVENT");
        }
        if (current_event != INVALID_EVENT){
            handle_event(current_event);
        }
    }
    printf("\n");
    fflush(stdout);
    
}
