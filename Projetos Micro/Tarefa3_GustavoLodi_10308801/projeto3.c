#include <at89x52.h>
#include <stdio.h>

void delay(void);//Config função delay
void configTimer(void);//Config função que configura o delay

void main(void)
{
	B = 0X00;//Contador inicializado no 0
	while(1){
		if(P0_1 == 1)//Porta que caso acionada força a parada do contador
		{
			B = B + 1;//Incremento do contador
			P1 = ~B;//P1 recebe NOT do contador em razão da configuração ânodo comum
			delay();//Chamada da função delay
		}
	}
}

void delay(void)
{
	configTimer();//Chamada da configuração
	while(TF0 == 0);//Loop até flag ativado que chegou em FFFF
	TR0 = 0;//Reset Timer0
	TF0 = 0;//Reset Flag
	
}

void configTimer(void)
{
	TMOD = 0X01;//Seta o working mode do timer, sendo os 4 bits menos significativos do timer0
	TH0 = 0XFC;//Valores do THO e TLO calculados pela diferença entre FFFF e 3CC(971 decimal)
	TL0 = 0X34;//3CB encontrado pelo período de 1 ms requisitado
	TR0 = 1;//Timer0 setado
}
