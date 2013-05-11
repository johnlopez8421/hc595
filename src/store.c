#include <hc595.h>
#include <util/delay.h>

void hc595_store(void)
{
	hc595_rclkwr(1);	// load
	//_delay_us(1);
	hc595_rclkwr(0);	// restore
	//_delay_us(1);
}