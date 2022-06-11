#include "buzzer.h"

void initBuzzer(){
	
	PINSEL_CFG_Type configBuzzer;
	
	cpt_duree = 0;
	flag_duree = false;
	cpt_note = 0;
	flag_note = false;
	index_note = 0;
	noteSonne = false;
	
	note = 0;
	
	configBuzzer.Funcnum = 2;
	configBuzzer.Portnum = 0;
	configBuzzer.Pinmode = 26;
	configBuzzer.Pinnum = 0;
	configBuzzer.OpenDrain = PINSEL_PINMODE_NORMAL;
	
	PINSEL_ConfigPin(&configBuzzer);
	
	GPIO_SetDir(0, 1<<26, 1);
	
	initialise_melodie1();
	note = tab_note[0];
}


int jouerNote(Note n, Octave o){
	
	return (int) (frequencesNotes[n]*pow(2.f, o));
}

void initialise_melodie1(){
	tab_note[0] = jouerNote(SI, 5);
	tab_duree_note[0] = BLANCHE;
	
	tab_note[1] = jouerNote(RE, 5);
	tab_duree_note[1] = NOIR;
	
	tab_note[2] = jouerNote(LA, 4);
	tab_duree_note[2] = BLANCHE;
	
	tab_note[3] = jouerNote(SOL,4);
	tab_duree_note[3] = DEMI;
	
	tab_note[4] = jouerNote(LA, 4);
	tab_duree_note[4] = DEMI;
	
	tab_note[5] = jouerNote(SI, 5);
	tab_duree_note[5] = BLANCHE;
	
	tab_note[6] = jouerNote(RE, 5);
	tab_duree_note[6] = NOIR;
	
	tab_note[7] = jouerNote(LA, 4);
	tab_duree_note[7] = POINTE;
	
	tab_note[8] = jouerNote(SI, 4);
	tab_duree_note[8] = BLANCHE;
	
	tab_note[9] = jouerNote(RE, 5);
	tab_duree_note[9] = NOIR;
	
	tab_note[10] = jouerNote(LA, 5);
	tab_duree_note[10] = BLANCHE;
	
	tab_note[11] = jouerNote(SOL,5);
	tab_duree_note[11] = NOIR;
	
	tab_note[12] = jouerNote(RE, 5);
	tab_duree_note[12] = BLANCHE;
	
	tab_note[13] = jouerNote(DO, 4);
	tab_duree_note[13] = DEMI;
	
	tab_note[14] = jouerNote(SI, 4);
	tab_duree_note[14] = DEMI;
	
	tab_note[15] = jouerNote(LA, 4);
	tab_duree_note[15] = BLANCHE;
}

void initTimer0(){
	
	TIM_TIMERCFG_Type configTimer;
	TIM_MATCHCFG_Type configMatch;
	
	configTimer.PrescaleOption = TIM_PRESCALE_USVAL;
	configTimer.PrescaleValue = 1;
	
	configMatch.MatchChannel = 2;
	configMatch.MatchValue = 10;
	configMatch.IntOnMatch = ENABLE;
	configMatch.StopOnMatch = DISABLE;
	configMatch.ResetOnMatch = ENABLE;
	configMatch.ExtMatchOutputType = TIM_EXTMATCH_NOTHING;
	
	TIM_Init(LPC_TIM0, TIM_TIMER_MODE, &configTimer);
	TIM_ConfigMatch(LPC_TIM0, &configMatch);
	
	NVIC_EnableIRQ(TIMER0_IRQn);
	
	TIM_Cmd(LPC_TIM0, ENABLE);
}

void startTimer0(){
	
	TIM_Cmd(LPC_TIM0, ENABLE);
}

void stopTimer0(){
	
	TIM_Cmd(LPC_TIM0, DISABLE);
	TIM_ResetCounter(LPC_TIM0);
}

void TIMER0_IRQHandler(){
	
	++cpt_duree;
	++cpt_note;
	
	if(cpt_duree == (int)(note/10.f)){
		
		flag_duree = true;
		cpt_duree = 0;
	}
	
	if(cpt_note == (uint8_t) 300){ // 300ms par note
		
		flag_note = true;
		cpt_note = 0;
		cpt_duree = 0;
	}
	
	TIM_ClearIntCapturePending(LPC_TIM0, TIM_MR2_INT);
}

void jouerBuzzer(){
	
	if(flag_duree){
		
		if(!noteSonne){
			
			GPIO_SetValue(0, (1 << 26));
		}
		else{
			
			GPIO_SetValue(0, (1 << 26));
		}
		
		noteSonne= !noteSonne;
		flag_duree = false;
	}
}

void jouerMelodie(void){
	
	if(index_note == 0){
		
		startTimer0();
	}
	
	if(flag_note){
		
		note = tab_note[index_note];
		index_note = (index_note + 1);
		
		if(index_note == 16){
			
			index_note = 0;
			stopTimer0();
		}
		
		flag_note = false;
	}
}
