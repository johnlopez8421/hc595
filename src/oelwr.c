#include <hc595.h>

void hc595_oelwr(uint8_t data)
{
	data &= 0x01;
	if(data)
	{
		HC595_OE_L_PORT |= HC595_OE_L;
	}
	else
	{
		HC595_OE_L_PORT &= ~HC595_OE_L;
	}
}