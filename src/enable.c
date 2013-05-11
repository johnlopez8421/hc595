#include <hc595.h>
#include <util/delay.h>

void hc595_enable(void)
{
	hc595_oelwr(0);	// OE* low
	//_delay_us(1);
}