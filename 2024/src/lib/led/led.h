/* lib/led/led.c */
void leds_off(void);
void reset_outputs(void);
void led_on(uint8_t led);
void all_on(uint8_t count);
void sequence(uint8_t count);
void left_side(uint8_t count);
void right_side(uint8_t count);
void pair(uint8_t number, uint8_t count);
void falling_sequence(uint8_t count);
