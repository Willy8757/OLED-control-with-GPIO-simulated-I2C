#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_init(void){
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
	//GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; no use in input
	
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}


uint8_t Key_getnum(void){
	uint8_t key_num = 0;
	if(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1)){
		Delay(20);
		while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_1));
		Delay(20);
		key_num = 1;
	}
	if(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11)){
		Delay(20);
		while(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11));
		Delay(20);
		key_num = 2;
	}
	
	return key_num;

}

