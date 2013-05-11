#include <hc595.h>
#include <util/delay.h>

void hc595_wr(uint8_t data)
{
	int j;
	for(j=0; j<8; j++)
	{
		hc595_srclkwr(0);	// clock low
		//_delay_us(1);
		hc595_serwr( (data & (1<<j))>>j );	// set data
		//_delay_us(1);
		hc595_srclkwr(1);	// clock high
		//_delay_us(1);
	}
	
}