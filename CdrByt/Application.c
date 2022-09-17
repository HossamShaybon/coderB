
############# Application.c ##############
#include "DIO_interface.h"
#include "UART_interface.h"
int main() {
DIO_voidSetPinDirection(0, 'D', IN);
DIO_voidSetPinDirection(1, 'D', OUT);
char data[9];
	while (1) {
		SWUART_recieve(data);
		SWUART_send(data);
	}
}

//////////////////////////////////////////////////////////
