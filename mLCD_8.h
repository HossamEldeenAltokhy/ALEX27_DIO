/* 
 * File:   mLCD_8.h
 * Author: hossa
 *
 * Created on May 28, 2022, 10:11 PM
 */

#ifndef MLCD_8_H
#define	MLCD_8_H
#include <avr/io.h>

#define LCD_DATA         PORTA
#define LCD_DATA_DIR     DDRA
#define LCD_CONTROL      PORTB
#define LCD_CONTROL_DIR  DDRB

#define RS          1
#define RW          2
#define EN          3



void init_LCD();
void init_LCD_4bit();
void LCD_send(unsigned char);
void LCD_send_4bit(unsigned char);
void LCD_send_str(unsigned char*);
void LCD_send_str_4bit(unsigned char*);
void LCD_send_num(int);
void LCD_send_num_4bit(int);

/// Commands
void LCD_cmd(unsigned char);
void LCD_cmd_4bit(unsigned char);
void LCD_clear();
void LCD_clear_4bit();
void LCD_enable();

#endif	/* MLCD_8_H */

