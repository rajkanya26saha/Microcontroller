
/*************************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 08-oct-2019		*/
/*Filename	: uart_timer.c	*/
/*Description	: source file for uart and timer implemention*/
/*************************************************************/

/* Included header files */
#include "uart_timer.h"

/* Global variable declarations*/
unsigned int sec=0;


/*main function definition */
void main(void)
{
while(1)
{
P1_0=0;
delay_500ms();
P1_0=1;
delay_500ms();
uart_init();
string("I am alive, ");
integer_ascii(sec);
string(" seconds");
uart_tx('\n');
uart_tx('\r');
sec++;
}
}

void delay_500ms(void)
{
unsigned char i;
for(i=0;i<10;i++)
{
TMOD=0X01;
TH0=0x4B;
TL0=0XFC;
TR0=1;
while(!TF0);
TF0=0;
TR0=0;
}
}

void uart_init(void)
{
TMOD=0X20;
TH1=0XFD;
SCON=0X50;
TR1=1;
}

void string(char *str)
{
 unsigned char i;
for(i=0;str[i]!='\0';i++)
{
uart_tx(str[i]);
}
}

void uart_tx(char msg)
{
SBUF=msg;
while(!TI);
TI=0;
}

void integer_ascii(int num)
{
int buffer[50];
int i=0,sec,a;
	if(num==0)
	{
	sec=num+'0';
	uart_tx(sec);
	}
while(num>0)
{
a=num%10;
buffer[i]=a;
num=num/10;
i++;
}
i--;
for(;i>=0;i--)
{
sec=buffer[i]+'0';
uart_tx(sec);
}

