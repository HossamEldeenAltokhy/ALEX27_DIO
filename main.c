/*
 * File:   main.c
 * Author: hossa
 *
 * Created on May 20, 2022, 9:14 PM
 */

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED0_DIR  DDRC2     // Data Direction Position
#define LED0      PC2       // PIN Position



int main(void) {
    /* Replace with your application code */
   
//    PORTA    
    /*
     * OUTPUT or INPUT      >>> DDRA 
     * (OUTPUT) HIGH or LOW >>> PORTA
     * (INPUT)  I_HIGH or I_LOW <<< PINA
     * 
     */
    // Direction
    DDRC  |= (1<<LED0_DIR);
    // Set Data
    PORTC |= (1<<LED0);
    
    
    
    while (1) {
        PORTC |= (1<<LED0);
        _delay_ms(500);
        PORTC &= ~(1<<LED0);
        _delay_ms(500);
    }
}
