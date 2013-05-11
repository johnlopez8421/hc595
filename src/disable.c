#include <hc595.h>
#include <util/delay.h>

void hc595_disable(void)
{
	hc595_oelwr(1);	 /* OE* high */
	//_delay_us(1);
}