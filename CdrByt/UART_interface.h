############# UART.c ##############
#include "UART_interface.h"
uint32_t baudrate= 51
void SWUART_init(uint32_t baudrate){
	UCSRA=0;
	UCSRA|=0<<1;
	UCSRA|=0<<0;
	/*
	 * select the character size in bit 2
	 */
	CLR_BIT(UCSRB, UCSRB_UCSZ2);

	UCSRC = 0b10101110;
	/*
	 * Set the Baud Rate 9600 bps
	 */
	UBRRL = baudrate ;

	/*
	 * Enable Rx, Tx, better enabling at end
	 */
	SET_BIT(UCSRB, UCSRB_TXEN);
	SET_BIT(UCSRB, UCSRB_RXEN);
}


 void SWUART_send(uint8_t data){
	while (GET_BIT(UCSRA,UCSRA_UDRE) == 0);
	UDR = copy_u8Data;
}
void SWUART_recieve(uint8_t *data) {
	while (GET_BIT(UCSRA,UCSRA_RXC) == 0);
	data=UDR;
}
