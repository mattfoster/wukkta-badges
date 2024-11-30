#define LED_DELAY 200  // delay in milliseconds
#define MAX_REPEATS 5
#define MAX_PROGS 3
#define TOTAL_LEDS 12

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sleep.h>
#include "led/led.h"

void enter_sleep_mode() {
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    sleep_cpu();
    // MCU goes to sleep here until an (INT0) interrupt occurs (or reset)
    sleep_disable();
}

int main(void) {
    while (1) {
        uint8_t count = 5;

        while(count) {
            all_on(150);
            leds_off();

            sequence(5);
            leds_off();

            left_side(70);
            leds_off();
            right_side(70);
            leds_off();
            left_side(70);
            leds_off();
            right_side(70);
            leds_off();

            all_on(150);
            leds_off();

            pair(0, 75);
            leds_off();
            pair(1, 75);
            leds_off();
            pair(2, 75);
            leds_off();
            pair(3, 75);
            leds_off();
            pair(4, 75);
            leds_off();
            pair(5, 75);
            leds_off();
            pair(6, 75);
            leds_off();
            pair(5, 75);
            leds_off();
            pair(4, 75);
            leds_off();
            pair(3, 75);
            leds_off();
            pair(2, 75);
            leds_off();
            pair(1, 75);
            leds_off();
            pair(0, 75);
            leds_off();

            all_on(75);
            leds_off();

            if (count == 1) {
                // 1010111
                pair(6, 75);
                leds_off();
                pair(4, 75);
                leds_off();
                pair(2, 75);
                leds_off();
                pair(1, 75);
                leds_off();
                pair(0, 75);
                leds_off();

                all_on(75);
                leds_off();

                // 1010101
                pair(6, 75);
                leds_off();
                pair(4, 75);
                leds_off();
                pair(2, 75);
                leds_off();
                pair(0, 75);
                leds_off();

                all_on(75);
                leds_off();

                // 1001011
                pair(6, 75);
                leds_off();
                pair(3, 75);
                leds_off();
                pair(1, 75);
                leds_off();
                pair(0, 75);
                leds_off();

                all_on(75);
                leds_off();

                // 1001011
                pair(6, 75);
                leds_off();
                pair(3, 75);
                leds_off();
                pair(1, 75);
                leds_off();
                pair(0, 75);
                leds_off();

                all_on(75);
                leds_off();

                // 1010100
                pair(6, 75);
                leds_off();
                pair(4, 75);
                leds_off();
                pair(2, 75);
                leds_off();

                all_on(75);
                leds_off();

                // 1000001
                pair(6, 75);
                leds_off();
                pair(0, 75);
                leds_off();

                all_on(75);
                leds_off();

                // 0100000
                pair(5, 75);
                leds_off();

                all_on(75);
                leds_off();

                // 0110010
                pair(5, 75);
                leds_off();
                pair(4, 75);
                leds_off();
                pair(1, 75);
                leds_off();

                all_on(75);
                leds_off();

                // 0110100
                pair(5, 75);
                leds_off();
                pair(4, 75);
                leds_off();
                pair(2, 75);
                leds_off();
            }

            all_on(100);
            leds_off();

            sequence(5);
            leds_off();

            falling_sequence(70);
            leds_off();
            falling_sequence(60);
            leds_off();
            falling_sequence(50);
            leds_off();
            falling_sequence(70);
            leds_off();
            falling_sequence(60);
            leds_off();
            falling_sequence(50);
            leds_off();
            falling_sequence(70);
            leds_off();
            falling_sequence(60);
            leds_off();
            falling_sequence(50);
            leds_off();

            count--;
        }

        enter_sleep_mode();
    }

    return 0;
}
