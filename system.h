#ifndef system_h
#define system_h

typedef enum {
    DONE,
    LOST,
    FAIL
} statsSetting;

typedef enum{
    ORDER_RECEIVED,
    INVALID_PAYMENT,
    VALID_PAYMENT,
    MANUFACTURE_COMPLETED,
    MANUFACTURE_FAILED,
    SHIPMENT_LOST,
    SHIPMENT_ARRIVED
} events;

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
