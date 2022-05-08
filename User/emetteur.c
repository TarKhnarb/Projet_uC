#include "emetteur.h"

	/**************
	 * initTimer0 *
	 **************/
void initTimer0(void){	// Initialise le TIM0 et de MAT0
	
	TIM_MATCHCFG_Type TIM_MatchConfigStruct;

	TIM_MODE_OPT TimerCounterMode = TIM_TIMER_MODE;
	TIM_TIMERCFG_Type TIM_ConfigStruct;
	TIM_ConfigStruct.PrescaleOption = TIM_PRESCALE_USVAL; //(1 << 2);
	TIM_ConfigStruct.PrescaleValue = 2500;

	TIM_MatchConfigStruct.MatchChannel = 0;		
	TIM_MatchConfigStruct.IntOnMatch = ENABLE;
	TIM_MatchConfigStruct.ResetOnMatch = ENABLE;
	TIM_MatchConfigStruct.StopOnMatch = ENABLE;
	TIM_MatchConfigStruct.ExtMatchOutputType = 0;
	TIM_MatchConfigStruct.MatchValue = 12;

	TIM_Init(LPC_TIM0, TimerCounterMode, &TIM_ConfigStruct);
	TIM_ConfigMatch(LPC_TIM0, &TIM_MatchConfigStruct);
}

	/***************
	 * startTimer0 *
	 ***************/
void startTimer0(void){	// Activation du timer 0
	
	TIM_ResetCounter(LPC_TIM0);	// Nécessaire ??
	TIM_Cmd(LPC_TIM0, ENABLE);
}

	/**************
	 * stopTimer0 *
	 **************/
void stopTimer0(void){
	
	TIM_Cmd(LPC_TIM0, DISABLE);	// On arrête le compteur 
	TIM_ResetCounter(LPC_TIM0);	// On remet à 0 le compteur
}

	/**************
	 * initTimer1 *
	 **************/
void initTimer1(void){
	
	TIM_MATCHCFG_Type TIM_MatchConfigStruct;

	TIM_MODE_OPT TimerCounterMode = TIM_TIMER_MODE;
	TIM_TIMERCFG_Type TIM_ConfigStruct;
	TIM_ConfigStruct.PrescaleOption = TIM_PRESCALE_USVAL;
	TIM_ConfigStruct.PrescaleValue = 2500;

	TIM_MatchConfigStruct.MatchChannel = 1;
	TIM_MatchConfigStruct.IntOnMatch = ENABLE;
	TIM_MatchConfigStruct.ResetOnMatch = ENABLE;
	TIM_MatchConfigStruct.StopOnMatch = ENABLE;
	TIM_MatchConfigStruct.ExtMatchOutputType = TIM_EXTMATCH_NOTHING;
	TIM_MatchConfigStruct.MatchValue = 100;	// par défaut

	TIM_Init(LPC_TIM1, TimerCounterMode, &TIM_ConfigStruct);
	TIM_ConfigMatch(LPC_TIM1, &TIM_MatchConfigStruct);
}

	/***************
	 * startTimer1 *
	 ***************/
void startTimer1(uint32_t duree){
	
	TIM_UpdateMatchValue(LPC_TIM1, 1, duree);	// On met à jour la durée du timer
	TIM_Cmd(LPC_TIM1, ENABLE);								// On démarre le compteur
	
	while(!flagTIM1);													// Tant que l'on a pas de levé de flag du timer 0 on attend
	flagTIM1 = 0;															// On baisse le flag du timer 0
}

	/*********************
	 * TIMER1_IRQHandler *
	 *********************/
void TIMER1_IRQHandler(void){
	
	stopTimer0();																// On arrête le timer 1
	flagTIM1 = true;														// On lève le flag du timer 1
	TIM_ClearIntPending(LPC_TIM1, TIM_MR1_INT);	// Acquittement de MR1
}

unsigned int getLength(char *msg){
	
	unsigned int toReturn = 0;
	while(msg[toReturn]){
		
		++toReturn;
	}
	
	return toReturn + 1;
}


	/***************
	 * sendMessage *
	 ***************/
void sendMessage(char *msg){
	
	unsigned char i, j;
	startTimer0();
	startTimer1(9600);	// Première modulation pendant 9000us
	startTimer1(4500);	// Remise à 0
	for(i = 0; i < 8; ++i){
		
		for(j = 0; j < 8; ++j){
			
			startTimer0();
			startTimer1(600);
			if(msg[i] << j & 0x01){
				
				startTimer1(2000);		// bit 0
			}
			else{
				
				startTimer1(1000);		// bit 1
			}
		}
	}
	startTimer0();	// Bit de stop
	startTimer1(600);
	startTimer1(10000);
}

