#include "Global.h"
#include "Device.h"
#include "MainEntry.h"
#include "usart.h"
#include "stdio.h"

extern unsigned char f10ms;

void HeartPulse(void);
extern ADI_16470_HandleTypeDef g_hImu16470;

void MainEntry(void)
{
	InitDevice();
  //uint8_t send_data_buf[2]={0x55,0x55};
    while (1)
    {
		HeartPulse();
  	if (f10ms==1)
		{
			f10ms = 0;
		  ADI_16470_ReadImu(&g_hImu16470);
		//HAL_Delay(1);
		//ADI_16470_ReadburstImu(&g_hImu16470);
    	ADI_16470_ParseImu(&g_hImu16470);
	//		printf("%f %f %f %f %f %f %f\n",g_hImu16470.fGyrX,g_hImu16470.fGyrY,g_hImu16470.fGyrZ,g_hImu16470.fAccX,g_hImu16470.fAccY,g_hImu16470.fAccZ,g_hImu16470.fTempretrue);
  //    HAL_UART_Transmit(&huart3, (uint8_t *)&send_data_buf[0], 2, 0xffff);
			HAL_Delay(1);
	  	ADI_16470_Readreg(&g_hImu16470);
			HAL_Delay(1);
		
		}
    }
}

void HeartPulse()
{
	static long counter = 0;
	counter++;
	if (counter>1000000)
	{
		counter = 0;
		LED_Toggle(LED1);
	}
}
