#include <avr/io.h>
#include "mDIO.h"

void LEDs_init(void) {
    // Configure Data Direction
    DDRC |= (1 << LED0_DIR) | (1 << LED1_DIR);
    DDRD |= (1 << LED2_DIR);
}

void setLED(unsigned char LED_no, unsigned char state) {
    if (state) {
        switch (LED_no) {
            case LED0:
            case LED1:
                PORTC |= (1 << LED_no);
                break;
            case LED2:
                PORTD |= (1 << LED_no);
                break;
            default:
                break;
        }
    } else {
        switch (LED_no) {
            case LED0:
            case LED1:
                PORTC &= ~(1 << LED_no);
                break;
            case LED2:
                PORTD &= ~(1 << LED_no);
                break;
            default:
                break;
        }
    }
}

void BTNs_init(void) {
    DDRB &= ~(1 << BTN0_DIR); // set PINB0 as INPUT
    //    DDRD &= ~(1 << BTN1_DIR); // set PINB0 as INPUT
    //    DDRD &= ~(1 << BTN2_DIR); // set PINB0 as INPUT
    DDRD &= ~((1 << BTN1_DIR) | (1 << BTN2_DIR)); // set PINB0 as INPUT
}

unsigned char isPressed(unsigned char BTN_no) {
    // BUTTON0
    if (BTN_no == BTN0) {
        if (PINB & (1 << BTN0)) {
            return ON;
        } else {
            return OFF;
        }
    }        // BUTTON 1 ,2
    else {
        if (PIND & (1 << BTN_no)) {
            return ON;
        } else {
            return OFF;
        }
    }
}