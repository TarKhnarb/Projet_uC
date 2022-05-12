#include "bluetooth.h"

void initBluetooth(){
		
	PINSEL_CFG_Type pinCfg;
	UART_CFG_Type uartCfg;
	UART_FIFO_CFG_Type uartFIFOCfg;	// configuration FIFO pour la gestion des tâches

	sensorToUpdate = 0;		// inittialisation de la variable d'actualisation des capteurs

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
	NVIC_EnableIRQ(UART0_IRQn);
	
	UART_FIFOConfigStructInit(&uartFIFOCfg);	// Configuration de base de FIFO
	UART_FIFOConfig(LPC_UART0,&uartFIFOCfg);
}

	/***************
	 * sendMessage *
	 ***************/
void sendMessage(char *msg){
	
	char tmpMessage[40];
	sprintf(tmpMessage, "%s", msg);
	UART_Send(LPC_UART0, (unsigned char*)tmpMessage, strlen(tmpMessage), BLOCKING);
}

	/***************
	 * sendInteger *
	 ***************/
void sendInteger(uint8_t value){
	
	UART_Send(LPC_UART0, &value, 1, BLOCKING); // ou sizeof(uint8_t <-> unsigned char)
}

void UART0_IRQHandler(){
	
	uint8_t buffer;
	
	UART_Receive(LPC_UART0, &buffer, 1, BLOCKING);
	
	switch(buffer){
		
		case 'A': // 0x41
			lcd_clear(Blue);
			numMenu = 0;
			break;
		
		case 'B': // 0x42
			lcd_clear(Blue);
			numMenu = 1;
			break;
		
		case 'D': // 0x44
			lcd_clear(Blue);
			numMenu = 2;
			break;
		
		default:
			lcd_clear(Blue);
			break;
	}
	
	//menu();	// A voir si encore necessaire
}


	/**************
	 * initTimer1 *
	 **************/
void initTimer1(){

	TIM_MATCHCFG_Type TIM_MatchConfigStruct;

	TIM_MODE_OPT TimerCounterMode = TIM_TIMER_MODE;
	TIM_TIMERCFG_Type TIM_ConfigStruct;
	TIM_ConfigStruct.PrescaleOption = TIM_PRESCALE_USVAL;
	TIM_ConfigStruct.PrescaleValue = 25000;	// précision 1ms

	TIM_MatchConfigStruct.MatchChannel = 2;
	TIM_MatchConfigStruct.IntOnMatch = ENABLE;
	TIM_MatchConfigStruct.ResetOnMatch = ENABLE;
	TIM_MatchConfigStruct.StopOnMatch = DISABLE;
	TIM_MatchConfigStruct.ExtMatchOutputType = TIM_EXTMATCH_NOTHING;
	TIM_MatchConfigStruct.MatchValue = 100;	// par défaut

	TIM_Init(LPC_TIM1, TimerCounterMode, &TIM_ConfigStruct);
	TIM_ConfigMatch(LPC_TIM1, &TIM_MatchConfigStruct);
	
	NVIC_EnableIRQ(TIMER1_IRQn);	// On active la fonction d'interruption
}

	/***************
	 * startTimer1 *
	 ***************/
void startTimer1(uint32_t duree){

	TIM_UpdateMatchValue(LPC_TIM1, 2, duree);	// On met à jour la durée du timer
	TIM_Cmd(LPC_TIM1, ENABLE);								// On démarre le compteur

	flagTIM1 = true;															// On lève le flag du timer 1
}

	/*********************
	 * TIMER1_IRQHandler *
	 *********************/
void TIMER1_IRQHandler(){

	sensorToUpdate = (sensorToUpdate + 1)%4;
	flagTIM1 = false;														// On baisse le flag du timer 1
	TIM_ClearIntPending(LPC_TIM1, TIM_MR2_INT);	// Acquittement de MR2
}
