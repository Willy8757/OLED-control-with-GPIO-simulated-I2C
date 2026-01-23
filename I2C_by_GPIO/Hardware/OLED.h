#ifndef __OLED_H
#define __OLED_H

void OLED_Init(void);
void OLED_I2C_start();
void OLED_I2C_stop();
void OLED_SendBytes(uint8_t Byt);
#endif
