/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f10x.h"
//#include <stdio.h>
//#include <string.h>
#include "stm32f10x_it.h"
#include "FreeRTOS.h"
#include "task.h"

/*Private Definition */
#define AVAILABLE 1
#define NOT_AVAILABLE 0

static void prvsetupHardware(void);
void vTask1_handler(void *params);
void vTask2_handler(void *params);
void print_msg(char *msg);

TaskHandle_t xTaskHandle_1 = NULL;
TaskHandle_t xTaskHandle_2 = NULL;


#ifdef USE_SEMIHOSTING
extern void initialise_monitor_handles();
#endif

uint8_t UART_periph;

int main(void)
{

#ifdef USE_SEMIHOSTING
	initialise_monitor_handles();
	printf("example code \n");
#endif

	volatile unsigned int *DWT_CYCCNT   = (volatile unsigned int *)0xE0001004; //address of the register
	volatile unsigned int *DWT_CONTROL  = (volatile unsigned int *)0xE0001000; //address of the register
	volatile unsigned int *DWT_LAR      = (volatile unsigned int *)0xE0001FB0; //address of the register
	volatile unsigned int *SCB_DEMCR    = (volatile unsigned int *)0xE000EDFC; //address of the register



	  *DWT_LAR = 0xC5ACCE55; // enable access
	  *SCB_DEMCR |= 0x01000000;
	  *DWT_CYCCNT = 0; // reset the counter
	  *DWT_CONTROL |= 1 ; // enable the counter
	RCC_DeInit();
	SystemCoreClockUpdate ();
	prvsetupHardware();
	print_msg("Example message of uart_print \r\n");
	 xTaskCreate(vTask1_handler,"Task-1",configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle_1);
	 xTaskCreate(vTask2_handler,"Task-2",configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle_2);

	//for(;;);
	 vTaskStartScheduler();
}

void vTask1_handler(void *params){

while(1){
	if(UART_periph == AVAILABLE){
				UART_periph = NOT_AVAILABLE;

			print_msg("print example code -task_1\r\n");
				UART_periph = AVAILABLE;
				 taskYIELD();
	   // printf("print example code -task_2 \n");


			print_msg("print example code -task_1\r\n");
				UART_periph = AVAILABLE;
				 taskYIELD();
	   // printf("print example code -task_2 \n");

		}
}

}

void vTask2_handler(void *params){

	while(1){
		if(UART_periph == AVAILABLE){
			UART_periph = NOT_AVAILABLE;

		print_msg("print example code -task_2\r\n");
			UART_periph = AVAILABLE;
			 taskYIELD();
   // printf("print example code -task_2 \n");

	}

   }
}
static void prvsetupHardware(){

	 GPIO_InitTypeDef GPIO_InitStructure;
	    USART_InitTypeDef USART_InitStructure;


	    /* Enable peripheral clocks for USART1 on GPIOA */
	    RCC_APB2PeriphClockCmd(
	        RCC_APB2Periph_USART1 |
	        RCC_APB2Periph_GPIOA |
	        RCC_APB2Periph_AFIO, ENABLE);

	    /* Configure PA9 and PA10 as USART1 TX/RX */

	    /* PA9 = alternate function push/pull output */
	    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	    GPIO_Init(GPIOA, &GPIO_InitStructure);

	    /* PA10 = floating input */
	    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	    GPIO_Init(GPIOA, &GPIO_InitStructure);

	    /* Configure and initialize usart... */
	    USART_InitStructure.USART_BaudRate = 9600;
	    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	    USART_InitStructure.USART_StopBits = USART_StopBits_1;
	    USART_InitStructure.USART_Parity = USART_Parity_No;
	    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	    USART_Init(USART1, &USART_InitStructure);

	    /* Enable USART1 */
	    USART_Cmd(USART1, ENABLE);
}

void print_msg(char *msg){

for(uint32_t i=0; i < strlen(msg); i++)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) != SET);
	USART_SendData(USART1, msg[i]);
}

}
