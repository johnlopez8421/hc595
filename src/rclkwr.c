#include <hc595.h>

void hc595_rclkwr(uint8_t data)
{
	data &= 0x01;
	if(data)
	{
		HC595_RCLK_PORT |= HC595_RCLK;
	}
	else
	{
		HC595_RCLK_PORT &= ~HC595_RCLK;
	}
}