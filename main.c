/*
 * File:   main.c
 * Author: hossa
 *
 * Created on May 20, 2022, 9:14 PM
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "mDIO.h"

// Comment
int main(void) {

    LEDs_init();
    BTNs_init();

    while (1) {

        setLED(LED0, isPressed(BTN0));
        setLED(LED1, isPressed(BTN1));
        setLED(LED2, isPressed(BTN2));


    }
}
