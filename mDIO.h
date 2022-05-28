/* 
 * File:   mDIO.h
 * Author: hossa
 *
 * Created on May 28, 2022, 9:53 PM
 */

#ifndef MDIO_H
#define	MDIO_H

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

#endif	/* MDIO_H */

