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
#include "mLCD_8.h"



char arr[] = {'A', 'B', 'C', '\0'};
unsigned char str[] = "Hello World!"; ///'\0'


// Comment

int main(void) {

    init_LCD();
    int x = 2022;
    while (1) {
        _delay_ms(1000);
        LCD_clear();
        LCD_send_num(x++);




    }
}
