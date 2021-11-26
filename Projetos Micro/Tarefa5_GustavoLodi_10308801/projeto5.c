#include <at89x52.h>
#include <stdio.h>

int digito0 = 0xF9;//Configurações dos dígitos no número USP
int digito1 = 0xC0;
int digito2 = 0xB0;
int digito3 = 0xC0;
int digito4 = 0x80;
int digito5 = 0x80;
int digito6 = 0xC0;
int digito7 = 0xF9;
int count = 0;

void delay(void);//Pré-config das funções de timer
void configTimer(void);

void main(void)
{
	while(1)
	{
		EX0 = 1;//Enabler dos timers
		EX1 = 1;
		EA = 1;
		if(count == 0)//caso não tenha alteração no count, configuração normal dos 4 primeiros
		{
			P0 = 0XFF;
			P1 = 0XFF;
			P2 = 0XFF;
			P3 = 0XFF;
			P0_3 = 0;
			P1 = digito0;
			delay();
			P0_3 = 1;
			P0_2 = 0;
			P1 = digito1;
			delay();
			P0_2 = 1;
			P0_1 = 0;
			P1 = digito2;
			delay();
			P0_1 = 1;
			P0_0 = 0;
			P1 = digito3;
			delay();
			P0_0 = 1;
		}

		else if(count == 1)//Deslocado pra direita
		{
			P0 = 0XFF;
			P1 = 0XFF;
			P2 = 0XFF;
			P3 = 0XFF;
			P0_3 = 0;
			P1 = digito1;
			delay();
			P0_3 = 1;
			P0_2 = 0;
			P1 = digito2;
			delay();
			P0_2 = 1;
			P0_1 = 0;
			P1 = digito3;
			delay();
			P0_1 = 1;
			P0_0 = 0;
			P1 = digito4;
			delay();
			P0_0 = 1;
		}

		else if(count == 2)//Deslocado 2 pra direita
		{
			P0 = 0XFF;
			P1 = 0XFF;
			P2 = 0XFF;
			P3 = 0XFF;
			P0_3 = 0;
			P1 = digito2;
			delay();
			P0_3 = 1;
			P0_2 = 0;
			P1 = digito3;
			delay();
			P0_2 = 1;
			P0_1 = 0;
			P1 = digito4;
			delay();
			P0_1 = 1;
			P0_0 = 0;
			P1 = digito5;
			delay();
			P0_0 = 1;
		}

		else if(count == 3)//Deslocado 3 pra direita
		{
			P0 = 0XFF;
			P1 = 0XFF;
			P2 = 0XFF;
			P3 = 0XFF;
			P0_3 = 0;
			P1 = digito3;
			delay();
			P0_3 = 1;
			P0_2 = 0;
			P1 = digito4;
			delay();
			P0_2 = 1;
			P0_1 = 0;
			P1 = digito5;
			delay();
			P0_1 = 1;
			P0_0 = 0;
			P1 = digito6;
			delay();
			P0_0 = 1;
		}

		else if(count == 4)//Deslocado 4 pra direita
		{
			P0 = 0XFF;
			P1 = 0XFF;
			P2 = 0XFF;
			P3 = 0XFF;
			P0_3 = 0;
			P1 = digito4;
			delay();
			P0_3 = 1;
			P0_2 = 0;
			P1 = digito5;
			delay();
			P0_2 = 1;
			P0_1 = 0;
			P1 = digito6;
			delay();
			P0_1 = 1;
			P0_0 = 0;
			P1 = digito7;
			delay();
			P0_0 = 1;
		}
		else if(count == 5)//Caso passe demais, retorna pra última posição
		{
			count = 4;
		}
		else if(count == -1)//Caso volte demais, retorna pra última posição
		{
			count = 0;
		}
		else//Tratamento de erros inesperados
		{
			count = 0;
		}
	}
}

void delay(void)
{
	configTimer();//Config dos valores setados no Timer0
	while(TF0 == 0);//Até flag TF0 ser acionada em nível lógico 1
	TR0 = 0;
	TF0 = 0;
}

void configTimer(void)
{
	TMOD = 0X01;//Valores calculados para o intervalo de 1ms
	TH0 = 0XFC;
	TL0 = 0X17;
	TR0 = 1;
}

void interrup0(void)__interrupt(0)
{
	count++;//Na interrupção para a direita, o contador count incrementa
	P0 = 0XFF;
	while(IE0);//Espera do desacionamento do botão
}

void interrup1(void)__interrupt(2)
{
	count--;//Na interrupção para a esquerda, o contador count decrementa
	P0 = 0XFF;
	while(IE1);//Espera do desacionamento do botão
}
