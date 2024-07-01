/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

//Where is LED connected? PA5
//Port: A
//Pin: 5

//Start of the Periph memory allocation. Unsigned Long
#define PERIPH_BASE				(0x40000000UL)

#define AHB1_PERIPH_OFFSET		(0x00020000UL)

// 0x4002 0000UL
#define AHB1_PERIPH_BASE		(PERIPH_BASE + AHB1_PERIPH_OFFSET)

#define GPIOA_OFFSET			(0x0000UL)
#define GPIOA_BASE				(AHB1_PERIPH_BASE + GPIOA_OFFSET)
#define RCC_OFFSET				(0x3800UL)
#define RCC_BASE				(AHB1_PERIPH_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET			(0x30UL)
#define RCC_AHB1EN_R			(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET 			(0x00UL)
#define GPIOA_MODE_R			(*(volatile unsigned int *) (GPIOA_BASE + MODE_R_OFFSET))

//Output Data Register Offset
#define OD_R_OFFSET				(0x14UL)
#define GPIOA_OD_R				(*(volatile unsigned int *) (GPIOA_BASE + OD_R_OFFSET))

//Shift last bit to 1
#define GPIOAEN 				(1U<<0)

#define PIN5					(1U<<5)
#define LED_PIN					PIN5


int main(void){

	//Enable clock access to GPIOA by setting last bit to 1
	RCC_AHB1EN_R |= GPIOAEN;

	//Set PA5 as output pin
	GPIOA_MODE_R |= (1U<<10); //Set bit 10 to 1

	//Clear bit 11 by setting it to 0
	GPIOA_MODE_R &= ~(1U<<11);

	//Forever loop
	while(1){

		//Turn on LED by setting PA5 high
		//GPIOA_OD_R |= LED_PIN;

		//Toggle PA5
		GPIOA_OD_R ^= LED_PIN;
		for(int i= 0;i<100000; i++){

		}
	}
}
