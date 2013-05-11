#include <hc595.h>

void hc595_serwr(uint8_t data)
{
	data &= 0x01;	// keep LSB
	if(data)
	{
		HC5959_SER_PORT |= HC595_SER;
	}
	else
	{	
		HC5959_SER_PORT &= ~HC595_SER;
	}
}