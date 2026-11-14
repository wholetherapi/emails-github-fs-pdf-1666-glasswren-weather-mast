#include "mast.h"
#include "rs485.h"

int main(void) {
    board_init();
    rs485_bus_init();
    sensor_power_init();

    while (1) {
        rs485_poll_all();
        sensor_power_cycle_if_due();
        board_low_power_sleep();
    }
}
