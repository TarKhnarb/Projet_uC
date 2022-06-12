#include "bluetooth.h"

void initBluetooth(){
		
	PINSEL_CFG_Type pinCfg;
	UART_CFG_Type uartCfg;
	UART_FIFO_CFG_Type uartFIFOCfg;	// configuration FIFO pour la gestion des tâches

	//(shema 3A)
	// Tx pin P0.2 
	pinCfg.Pinnum = 2;
	pinCfg.Portnum = 0;
	pinCfg.Funcnum = 1;	
	pinCfg.Pinmode = PINSEL_PINMODE_TRISTATE;
	pinCfg.OpenDrain = PINSEL_PINMODE_OPENDRAIN;
	
	PINSEL_ConfigPin(&pinCfg);
	
	// Rx pin P0.3
	pinCfg.Pinnum = 3;
	PINSEL_ConfigPin(&pinCfg);
	
	// UART
	uartCfg.Baud_rate = 38400;
	uartCfg.Parity = UART_PARITY_NONE;
	uartCfg.Databits = UART_DATABIT_8;
	uartCfg.Stopbits = UART_STOPBIT_1;
	
	UART_Init(LPC_UART0, &uartCfg);
	UART_TxCmd(LPC_UART0, ENABLE);											// Activation de l'envoie de données
	UART_IntConfig(LPC_UART0, UART_INTCFG_RBR, ENABLE);	// Activation des interruptions sur l'uart0
	NVIC_EnableIRQ(UART0_IRQn);	// Ajout de l'interruption pour l'uart0
	
	UART_FIFOConfigStructInit(&uartFIFOCfg);	// Configuration de base du mode FIFO pour l'uart (évite les soucis lors de l'envoie/recption simutané)
	UART_FIFOConfig(LPC_UART0, &uartFIFOCfg);	// Configuration de l'uart0 en mode FIFO
}

	/***************
	 * sendMessage *
	 ***************/
void sendMessage(char *msg){
	
	char tmpMessage[40];
	sprintf(tmpMessage, "%s", msg); // On concatène le message à envoyer dans le buffer
	UART_Send(LPC_UART0, (unsigned char*)tmpMessage, strlen(tmpMessage), BLOCKING);
}

	/***************
	 * sendInteger *
	 ***************/
void sendInteger(uint8_t value){
	
	UART_Send(LPC_UART0, &value, 1, BLOCKING); // ou sizeof(uint8_t <-> unsigned char)
}

void UART0_IRQHandler(){
	
	uint8_t buffer = UART_ReceiveByte(LPC_UART0); // On récupère le caractère evoyé par l'application du téléphone
	
	//UART_Receive(LPC_UART0, &buffer, 1, BLOCKING);
	
	switch(buffer){	// Suivant la valeur on change le menu
		
		case 0x41: //'A':
			lcd_clear(Blue);
			numMenu = 0;
			break;
		
		case 0x42: //'B':
			lcd_clear(Blue);
			numMenu = 1;
			break;
		
		case 0x44://'D':
			lcd_clear(Blue);
			numMenu = 2;
			break;
		
		default:
			lcd_clear(Blue);
			break;
	}
}
