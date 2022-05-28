/*
 * File:   main.c
 * Author: hossa
 *
 * Created on May 20, 2022, 9:14 PM
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#define ON   1
#define OFF  0


#define LED0_DIR  DDRC2     // Data Direction Position
#define LED0      PORTC2    // PIN Position
#define LED1_DIR  DDRC7     // Data Direction Position
#define LED1      PORTC7    // PIN Position
#define LED2_DIR  DDRD3     // Data Direction Position
#define LED2      PORTD3    // PIN Position

#define BTN0_DIR  DDRB0
#define BTN0      PORTB0    // PINB0
#define BTN1_DIR  DDRD6
#define BTN1      PORTD6    // PINB0
#define BTN2_DIR  DDRD2
#define BTN2      PORTD2    // PINB0


void LEDs_init(void);
void setLED(unsigned char LED_no, unsigned char state);

void BTNs_init(void);
unsigned char isPressed(unsigned char BTN_no);
// Comment
int main(void) {

    LEDs_init(void);
    BTNs_init(void);

    while (1) {
//        if (isPressed(BTN0)) {
//            setLED(LED0, ON);
//            setLED(LED1, OFF);
//            setLED(LED2, ON);
//        } else {
//            setLED(LED0, OFF);
//            setLED(LED1, ON);
//            setLED(LED2, OFF);
//        }

        setLED(LED0, isPressed(BTN0));
        setLED(LED1, isPressed(BTN1));
        setLED(LED2, isPressed(BTN2));


    }
}

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