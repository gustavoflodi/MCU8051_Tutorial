#include <at89x52.h>

void delay(unsigned int);//Declaração da função de latência caso seja usada

void main(void)
{
	P0 = 0xFF;//Setado para não-acionado 
	P1 = 0xFF;//Setado para não-acionado
	delay(5);//Latência para entrar no loop
	while(1)
	{
		if(P0_0 == 0)//Se botão 0_1 setado como acionado
		{
			while(P0_0 == 0)//O LED mantém-se como acionado enquanto o botão está acionado
			{
				P1_0 = 0;//LED acionado
			}
			//delay(10);//Função comentada, porém disponível para atraso
			P1_0 = 1;
		}
		//Para os demais pares de botão e LED, a mesma lógica se aplica
		if(P0_1 == 0)
		{
			while(P0_1 == 0)
			{
				P1_1 = 0;
			}
			//delay(10);
			P1_1 = 1;
		}
		if(P0_2 == 0)
		{
			while(P0_2 == 0)
			{
				P1_2 = 0;
			}
			//delay(10);
			P1_2 = 1;
		}
		if(P0_3 == 0)
		{
			while(P0_3 == 0)
			{
				P1_3 = 0;
			}
			//delay(10);
			P1_3 = 1;
		}
		if(P0_4 == 0)
		{
			while(P0_4 == 0)
			{
				P1_4 = 0;
			}
			//delay(10);
			P1_4 = 1;
		}
		if(P0_5 == 0)
		{
			while(P0_5 == 0)
			{
				P1_5 = 0;
			}
			//delay(10);
			P1_5 = 1;
		}
		if(P0_6 == 0)
		{
			while(P0_6 == 0)
			{
				P1_6 = 0;
			}
			//delay(10);
			P1_6 = 1;
		}
		if(P0_7 == 0)
		{
			while(P0_7 == 0)
			{
				P1_7 = 0;
			}
			//delay(10);
			P1_7 = 1;
		}
	}
}

void delay(unsigned int count)//Função atraso por meio de loop em sintaxe C
{
	while(count)
	{
		count--;
	}
}