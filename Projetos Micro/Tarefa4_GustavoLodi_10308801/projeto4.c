#include <at89x52.h>
#include <stdio.h>

void delay(void);//Pre-configurações das funções adicionais
void configTimer(void);
void delay1(void);
void configTimer1(void);

int temp = 0;//Variável global para auxiliar a a transição Subtração -> Soma

void main(void)
{
	EX0 = 1;//Setagem das variáveis de Enable e Prioridade para as interrupções externas
	EX1 = 1;
	PX0 = 1;
	EA = 1;
	B = 0X00;//B resetado para começar no 0x00
	while(1){
		if(P0_1 == 1)//Enabler do contador
		{
			if (temp != 0)//Caso temp não seja 0, a transição Subtração -> Soma existe e deve resumir do valor atual de B
			{
				B = temp;
			}
			temp = 0;
			B = B + 1;//Próximo valor
			P1 = ~B;//Config ânodo comum: LED aceso em 0
			delay();
		}
	}
}

void interrup0(void)__interrupt(0)
{
	while(IE0);//Pausado até desacionado
}

void interrup1(void)__interrupt(2)
{
	while(IE1)//Funcionamento igual a main(), porém decrementando B
	{
		if(P0_1 == 1)
		{
			B = B - 1;
			P1 = ~B;
			delay1();
		}
	}
	TF0 = 1;
	temp = B;
}

void delay(void)
{
	configTimer();//Timer setado para Soma
	while(TF0 == 0);//flag TF0 acionada em valar alto
	TR0 = 0;//Reset para próximo delay
	TF0 = 0;
	
}

void delay1(void)
{
	configTimer1();//Timer setado para Subtração
	while(TF0 == 0);//flag TF0 acionada em valar alto
	TR0 = 0;//Reset para próximo delay
	TF0 = 0;
	
}

void configTimer(void)
{
	TMOD = 0X01;//Valores encontrados por meio do cálculo do intervalo requerido e da compensação do conjunto de instruções adicionais do micro
	TH0 = 0XFC;
	TL0 = 0X3B;
	TR0 = 1;
}

void configTimer1(void)
{
	TMOD = 0X01;//Valores encontrados por meio do cálculo do intervalo requerido e da compensação do conjunto de instruções adicionais do micro
	TH0 = 0XFC;
	TL0 = 0X35;
	TR0 = 1;
}
