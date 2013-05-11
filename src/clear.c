#include <hc595.h>
#include <util/delay.h>


void hc595_clear(void)
{
	hc595_srclrlwr(0);	// clear
	//_delay_us(1);
	hc595_srclrlwr(1);	// un-clear
	//_delay_us(1);
}