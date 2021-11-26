#include <at89x52.h>

void delay(unsigned int);


void main (void)
{
	while(1)
	{
		P0 = 0X00;//7 LEDs setados como acionados 
		delay(110);//Delay de 1ms
		P0 = 0XFF;//7 LEDs setados como apagados 
		delay(109);//Delay de 1ms
	}
}

void delay(unsigned int count)
{
	while(count)
	{
		count--;
	}
}