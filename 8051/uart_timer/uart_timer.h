
/****************************************************************/
/*Author	: Rajkanya Saha		*/
/*Date		: 08-oct-2019		*/
/*Filename	: uart_timer.h	*/
/*Description	: header files for uart and timer implementation*/
/****************************************************************/

#ifndef UART_TIMER_H
#define UART_TIMER_H

/* Included header files */

#include <REGX51.H>


/* function prototypes */

void delay_500ms(void);
void uart_init(void);
void string(char *str);
void uart_tx(char msg);
void integer_ascii(int num);




/* Macro Definitions */





/* user defined datatypes definitions */




#endif //UART_TIMER_H
