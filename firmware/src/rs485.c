#include "rs485.h"

void rs485_bus_init(void) {
    uart_configure(RS485_BAUD, RS485_PARITY);
    de_configure_pin();
}

int rs485_poll_all(void) {
    uint8_t count = 0;
    for (uint8_t address = 1; address <= GLASSWREN_MAX_SENSOR; address++) {
        if (rs485_poll(address) == SENSOR_OK) {
            count++;
        }
    }
    return count;
}
