#include "delay.h"
#include "LPC11xx.h"
void Delay(uint32_t ulTime)
{
	uint32_t i;
	i=0;
	while(ulTime--)
	{
		for(i=0;i<5000;i++);
	}
}
