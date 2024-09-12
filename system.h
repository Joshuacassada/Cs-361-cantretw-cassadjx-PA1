#ifndef SYSTEM_H
#define SYSTEM_H

typedef enum {
    DONE,
    LOST,
    FAIL
} statsSetting;

extern int payAttempts;
extern int order_size;

void chargeClient();
void paymentRejected();
void refund();
void startWarranty();

void getOrderSize();
void resetAttempts();
void incrementAttempts();
void updateStats(statsSetting value);

#endif
