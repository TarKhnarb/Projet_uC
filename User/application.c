#include "application.h"

	/*******************
	 * initialisations *
	 *******************/
void initialisations(){
	
	initMenu();				// On initialise l'écran LCD
	initBluetooth();	// On initialise le bluetooth
	initTimer1();			// On initialise le timer qui met à jour les valeurs des capteurs
	initSensors();		// On initialise les différents capteurs
	
	sensorToUpdate = 0;		// inittialisation de la variable d'actualisation des capteurs

	//initBuzzer();		// On initialise le buzzer
	//initTimer0();		// On initialise le timer du buzzer
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

	flagTIM1 = true;													// On lève le flag du timer 1
}

	/*********************
	 * TIMER1_IRQHandler *
	 *********************/
void TIMER1_IRQHandler(){

	sensorToUpdate = (sensorToUpdate + 1)%4;
	flagTIM1 = false;														// On baisse le flag du timer 1
	TIM_ClearIntPending(LPC_TIM1, TIM_MR2_INT);	// Acquittement de MR2
}

void boutons(){
	
	bool bp = ((GPIO_ReadValue(2)>>10)&0x1);	// On récupère l'état de la broche du bouton 2 (p0.12)
	unsigned int i;		// Initialisation de la valeur permettant de temporéser et donc d'éviter les rebonds
	
	if(bp != oldMaintienBouton){	// S'il l'on détecte un changement de front
		
		for(i = 0; i < 1000; ++i){}
		if(bp){	// Si on détecte un front montant
			
			lcd_clear(Blue);						// On repeint l'écran en bleu
			numMenu = (numMenu + 1)%3;	// On incrémente la variable du menu
			//jouerMelodie();	// On lance la mélodie
		}
	}
	
	//jouerBuzzer();		// On joue la note 
	oldMaintienBouton = bp;	// On sauvegarde l'ancien etat du outon
  getRainSensor();				// On vérifie l'état du capteur d'eau (p0.11)
}

char* concatene(char caractere, uint32_t value){
	
	// On concatène le caracère suivis d'un foat précis au dixièmes, le tous encadré d'*
	sprintf(stringToSend, "*%c%.1f*", caractere, (float)value);
	
	return &(stringToSend[0]);
}

void getWeatherIcon(){
	
	if(pluie){
		
		if(temperature > 0.f){ // Pluie
			
			temps = 3;
		}
		else{	// Neige
			
			temps = 4;
		}
	}
	else if(luminosite > 99.f && !pluie){ // Soleil
		
		temps = 1;
	}
	
	else if(luminosite < 50.f && !pluie){	// Nuage
		
		temps = 2;
	}
}

void setDayNightIcon(){
	
	if(luminosite < 10.f){
		
		jourNuit = 0;
	}
	else{
		
		jourNuit = 1;
	}
}

void bluetooth(){

	if(!flagTIM1){	// Si l'interruption du timer 1 à été réalisée, 
		
		startTimer1(50); // On démarre le timer pour une durée de 50 ms
		if(sensorToUpdate == 0){
			
			getTempSensor();	// On met à jour la valeur du capteur de température
			sendMessage(concatene('T', temperature));	// On concatène et envoie les informations au téléphone
		}
		else if(sensorToUpdate == 1){
			
			getLightSensor();	// On met à jour la valeur du capteur de luminosité
			setDayNightIcon();	// On met a jour le apteur de jour/nuit
			sendMessage(concatene('L', luminosite));	// On concatène et envoie les informations à l'application
		}
		else if(sensorToUpdate == 2){
			
			co2 = 30;	// Valeur par défaut en attente de l'implémentation du capteur de CO2
			sendMessage(concatene('C', co2));
		}
		else if(sensorToUpdate == 3){
			
			humidite = 50.f;	// Valeur par défaut en attente de l'implémentation du capteur d'humidité/Température
			sendMessage(concatene('H', humidite)); 
		}
	}
	
	getWeatherIcon();		// On met à jour l'icône du temps
}

void stationMeteo(){
	
	boutons();		// On récupère les valeurs des boutons
	bluetooth();	// On met à jour ou non les valeurs des capteurs
	menu();				// On affiche l'écran LCD
}
