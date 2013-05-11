#include <hc595.h>

void hc595_srclrlwr(uint8_t data)
{
	data &= 0x01;
	if(data)
	{
		HC595_SRCLR_L_PORT |= HC595_SRCLR_L;
	}
	else
	{
		HC595_SRCLR_L_PORT &= ~HC595_SRCLR_L;
	}
}