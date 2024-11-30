#include <avr/io.h>
#include <util/delay.h>

#include "led.h"

void leds_off() {
    DDRB &= ~(_BV(DDB1) | _BV(DDB2) | _BV(DDB3) | _BV(DDB4));
}

void reset_outputs() {
    DDRB |= (_BV(DDB1) | _BV(DDB2) | _BV(DDB3) | _BV(DDB4));
}

void led_on(uint8_t led) {
    switch(led) {
        case  1: // 1 - 2
            // Turn off by setting as inputs
            DDRB &= ~(_BV(DDB3) | _BV(DDB4));
            // Enable as outputs
            DDRB |= _BV(DDB1) | _BV(DDB2);

            PORTB |= _BV(PB1);
            PORTB &= ~(_BV(PB2));
            break;

        case  2: // 2 - 1
            // Turn off by setting as inputs
            DDRB &= ~(_BV(DDB3) | _BV(DDB4));
            // Enable as outputs
            DDRB |= _BV(DDB1) | _BV(DDB2);

            PORTB |= _BV(PB2);
            PORTB &= ~(_BV(PB1));
            break;

        case  3: // 2 - 3 
            // Turn off by setting as inputs
            DDRB &= ~(_BV(DDB1) | _BV(DDB4));
            // Enable as outputs
            DDRB |= _BV(DDB2) | _BV(DDB3);

            PORTB |= _BV(PB2);
            PORTB &= ~(_BV(PB3));
            break;

        case  4: // 3 - 2
            // Turn off by setting as inputs
            DDRB &= ~(_BV(DDB1) | _BV(DDB4));
            // Enable as outputs
            DDRB |= _BV(DDB2) | _BV(DDB3);

            PORTB |= _BV(PB3);
            PORTB &= ~(_BV(PB2));
            break;

        case  5: // 3 - 4
            // Turn off by setting as inputs
            DDRB &= ~(_BV(DDB1) | _BV(DDB2));
            // Enable as outputs
            DDRB |= _BV(DDB3) | _BV(DDB4);

            PORTB |= _BV(PB3);
            PORTB &= ~(_BV(PB4));
            break;

        case  6: // 4 - 3
            // Turn off by setting as inputs
            DDRB &= ~(_BV(DDB1) | _BV(DDB2));
            // Enable as outputs
            DDRB |= _BV(DDB3) | _BV(DDB4);

            PORTB |= _BV(PB4);
            PORTB &= ~(_BV(PB3));
            break;

        case  7: // 1 - 3
            // Turn off by setting as inputs
            DDRB &= ~(_BV(DDB2) | _BV(DDB4));
            // Enable as outputs
            DDRB |= _BV(DDB1) | _BV(DDB3);

            PORTB |= _BV(PB1);
            PORTB &= ~(_BV(PB3));
            break;

        case  8: // 3 - 1
            // Turn off by setting as inputs
            DDRB &= ~(_BV(DDB2) | _BV(DDB4));
            // Enable as outputs
            DDRB |= _BV(DDB1) | _BV(DDB3);

            PORTB |= _BV(PB3);
            PORTB &= ~(_BV(PB1));
            break;

        case  10: // 1 - 4 (pos 10 on board)
            // Turn off by setting as inputs
            DDRB &= ~(_BV(DDB2) | _BV(DDB3));
            // Enable as outputs
            DDRB |= _BV(DDB1) | _BV(DDB4);

            PORTB |= _BV(PB1);   // Set PB4 high
            PORTB &= ~(_BV(PB4));  // Set PB3 low
            break;

        case  11: // 4 - 1
            // Turn off by setting as inputs
            DDRB &= ~(_BV(DDB2) | _BV(DDB3));
            // Enable as outputs
            DDRB |= _BV(DDB1) | _BV(DDB4);

            PORTB |= _BV(PB4);   // Set PB4 high
            PORTB &= ~(_BV(PB1));  // Set PB3 low
            break;

        case  12: // 2 - 4
            // Turn off by setting as inputs
            DDRB &= ~(_BV(DDB1) | _BV(DDB3));
            // Enable as outputs
            DDRB |= _BV(DDB2) | _BV(DDB4);

            PORTB |= _BV(PB2);   // Set PB4 high
            PORTB &= ~(_BV(PB4));  // Set PB3 low
            break;

        case  9: // 4 - 2 (pos 9 on board)
            // Turn off by setting as inputs
            DDRB &= ~(_BV(DDB1) | _BV(DDB3));
            // Enable as outputs
            DDRB |= _BV(DDB2) | _BV(DDB4);

            PORTB |= _BV(PB4);   // Set PB4 high
            PORTB &= ~(_BV(PB2));  // Set PB3 low
            break;
    }
}

// rapidly power on all LEDS in a loop, attempting to make it looks like they're all lit
void all_on(uint8_t count) {
    while(count) {
        for (uint8_t jj = 1;jj<=12; jj++) {
            led_on(jj);
            _delay_ms(1);
        }
        count--;
    }
}

// as above but much slower
void sequence(uint8_t count) {
    while(count) {
        for (uint8_t jj = 1;jj<=12; jj++) {
            led_on(jj);
            _delay_ms(75);
        }
        count--;
    }
}

void left_side(uint8_t count) {
    while(count) {
        for (uint8_t jj = 1;jj<=4; jj++) {
            led_on(jj);
            _delay_ms(1);
        }

        led_on(11);
        _delay_ms(1);
        led_on(12);
        _delay_ms(1);

        count--;
    }
}

void right_side(uint8_t count) {
    while(count) {
        for (uint8_t jj = 5;jj<=10; jj++) {
            led_on(jj);
            _delay_ms(1);
        }
        count--;
    }
}

// Light one of 7 pairs of LEDs to represent 7 bits
void pair(uint8_t number, uint8_t count) {
    while(count) {
        switch(number) {
            case 6:
                led_on(1);
                _delay_ms(1);
                led_on(2);
                break;
            case 5:
                led_on(3);
                _delay_ms(1);
                led_on(12);
                break;
            case 4:
                led_on(4);
                _delay_ms(1);
                led_on(11);
                break;
            case 3:
                led_on(10);
                _delay_ms(1);
                led_on(11);
                break;
            case 2:
                led_on(5);
                _delay_ms(1);
                led_on(10);
                break;
            case 1:
                led_on(6);
                _delay_ms(1);
                led_on(9);
                break;
            case 0:
                led_on(7);
                _delay_ms(1);
                led_on(8);
                break;
        }
        _delay_ms(1);
        leds_off();
        count--;
    }
}

void falling_sequence(uint8_t count) {
    uint8_t original_count = count;

    while(count) {
        _delay_ms(1);
        led_on(1);
        _delay_ms(1);
        led_on(8);
        count --;
    }

    count = original_count;

    while(count) {
        _delay_ms(1);
        led_on(2);
        _delay_ms(1);
        led_on(7);
        count--;
    }

    count = original_count;    

    while(count) {
        _delay_ms(1);
        led_on(3);
        _delay_ms(1);
        led_on(12);
        _delay_ms(1);
        led_on(6);
        _delay_ms(1);
        led_on(9);
        count--;
    }

    count = original_count;    

    while(count) {
        _delay_ms(1);
        led_on(4);
        _delay_ms(1);
        led_on(11);
        _delay_ms(1);
        led_on(5);
        _delay_ms(1);
        led_on(10);
        count--;
    }
}

