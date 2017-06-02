
#include "LPC11xx.h"
#include "uart.h"
#include "delay.h"
#include "ADC.h"
#include "oled.h"
#include <stdio.h>
#include <string.h>
#define UART_BPS  9600
char  GcRcvBuf[20];

int main()
{ 
	
	float t,k;
	uint32_t ulADCData;
	uint32_t i;
	uint32_t ulADCBuf;
	uint32_t res_value;
	UART_Init ();
	ADC_Init ();
	OLED_Init();
	//LPC_GPIO2->DIR  = 0xFF;
	while(1)
	{
    ulADCData=0;
    for(i=0;i<10;i++)
     {
			 LPC_ADC->CR |=(1<<24);
			 while((LPC_ADC ->DR[7]&0x80000000)==0);
			 LPC_ADC->CR |=(1<<24);
			 while((LPC_ADC ->DR[7]&0x80000000)==0);
			 ulADCBuf =LPC_ADC->DR[7];
			 ulADCBuf =(ulADCBuf >>6)&0x3ff;
			 ulADCData+=ulADCBuf ;
		 }	
    ulADCData=ulADCData/10;
		 

    ulADCData=(ulADCData*3300)/1024;
		res_value = ((ulADCData*10000)/(3300-ulADCData));
		 
		 
	if((res_value<33970)&&(res_value>20310))  //0-10
	{
			k = 1366;
		  t = (33970-res_value)/k;
	}		
	else if ((res_value<20310)&&(res_value>12570)) //10-20
	{
			k = 774;
		  t = (20310-res_value)/k+10;
	}
	else if ((res_value<12570)&&(res_value>8034)) //20-30
	{
			k = 453.7;
		  t = ((12570-res_value)/k)+20;
	}
	else if ((res_value<8034)&&(res_value>5298))  //30-40
	{
			k = 273.7;
		  t = ((8034-res_value)/k)+30;
	}
	else if ((res_value<5298)&&(res_value>3586))  //40-50
	{
			k = 171.7;
		  t = ((5298-res_value)/k)+40;
	}
	else if ((res_value<3586)&&(res_value>2484))  //50-60
	{   k = 110.2;
		  t = ((3586-res_value)/k)+50;
	}
	
	
		 
    sprintf (GcRcvBuf,"temp = %4f C\r\n", t);
	  UART_SendStr(GcRcvBuf);
	
	   OLED_Print(0,0, "ang\0");
//		 Delay (200)
//		 if(ulADCData<400)                   LPC_GPIO2->DATA = 0xFE;
//		if(ulADCData>400&&ulADCData<800)    LPC_GPIO2->DATA = 0xFC;
//		if(ulADCData>800&&ulADCData<1200)   LPC_GPIO2->DATA = 0xF8;
//		if(ulADCData>1200&&ulADCData<1600)  LPC_GPIO2->DATA = 0xF0;
//		if(ulADCData>1600&&ulADCData<2000)  LPC_GPIO2->DATA = 0xE0;
//		if(ulADCData>2000&&ulADCData<2400)  LPC_GPIO2->DATA = 0xC0;
//		if(ulADCData>2400&&ulADCData<2800)  LPC_GPIO2->DATA = 0x80;
//		if(ulADCData>2800&&ulADCData<3300)  LPC_GPIO2->DATA = 0x00;
		 


//int32_t  CaculTwoPoint(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t x)
//{
//    return y1 + ((int64_t)(y2 - y1) * (x - x1)) / (x2 - x1);
//}	 
	
	}
}
