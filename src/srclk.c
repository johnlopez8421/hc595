#include <hc595.h>

void hc595_srclkwr(uint8_t data)
{
	data &= 0x01;
	if(data)
	{
		HC595_SRCLK_PORT |= HC595_SRCLK;
	}
	else
	{
		HC595_SRCLK_PORT &= ~HC595_SRCLK;
	}
}