#define F_CPU 16000000UL
#include <util/delay.h>
#include "mLCD_8.h"
#include <stdlib.h>

void init_LCD(){
    // not now
    // PIN Configurations.
    // set Data pins as OUTPUT
    LCD_DATA_DIR = 0xff;
    
    // set control pins as OUTPUT
    LCD_CONTROL_DIR |= (1<<RS)|(1<<EN)|(1<<RW);
    _delay_ms(10);
    LCD_CONTROL &= ~(1<<RW);
    
    LCD_clear();
    LCD_cmd(0x02); // Return home
    LCD_cmd(0x38); // 2 lines and 5×7 matrix
    LCD_cmd(0x0C); // Display ON, cursor OFF
    LCD_cmd(0x80); // Force cursor to beginning of first line
    
    _delay_ms(10);
}
void LCD_send(unsigned char data){
    LCD_DATA = data;
    LCD_CONTROL |= (1<<RS); // Select Data Register
    LCD_enable();
    _delay_ms(2);
}
void LCD_send_str(unsigned char* str){
    for(int i =0 ; str[i]!= '\0'; i++){
        LCD_send(str[i]);
        //LCD_send(*(str+i));
    }
}
void LCD_send_num(int num){
    char buf[11];
    itoa(num, buf, 10);
    LCD_send_str((unsigned char *)buf);
}

/// Commands
void LCD_cmd(unsigned char cmd){
    LCD_DATA = cmd;
    LCD_CONTROL &= ~(1<<RS);// Select Instruction Register
    LCD_enable();
    _delay_ms(2);
}
void LCD_clear(){
    LCD_cmd(0x01);
}
void LCD_enable(){
    LCD_CONTROL |= (1<<EN);
    _delay_ms(5);
    LCD_CONTROL &= ~(1<<EN);
}