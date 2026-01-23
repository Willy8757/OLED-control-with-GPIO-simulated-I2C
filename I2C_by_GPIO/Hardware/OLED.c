#include "stm32f10x.h"
#include "OLED_Font.h"
#include "Delay.h"

#define OLED_SCL(x)		GPIO_WriteBit(GPIOB, GPIO_Pin_8, (BitAction)(x))
#define OLED_SDA(x)		GPIO_WriteBit(GPIOB, GPIO_Pin_9, (BitAction)(x))

void OLED_I2C_Init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD; //Open drain
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
 	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	OLED_SCL(1);
	OLED_SDA(1);
}


void OLED_I2C_start(){
	
	OLED_SDA(1); //init
	OLED_SCL(1);
	OLED_SDA(0); //start : SDA go down when SCL = 1
	OLED_SCL(0); //transmit when SCL = 1

}

void OLED_I2C_stop(){
	
	OLED_SDA(0);
	OLED_SCL(1);
	OLED_SDA(1); //stop

}


void OLED_SendBytes(uint8_t Byt){
	for(uint8_t i = 0; i < 8; i++){
		OLED_SDA(Byt & (0x80 >> i)); //send hightest bit
		Delay_us(5);
		OLED_SCL(1);
		Delay_us(5);
		OLED_SCL(0);
		Delay_us(5);
	}
	OLED_SCL(1);
	Delay_us(5);
	OLED_SCL(0);

}






