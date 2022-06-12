#include "application.h"

	/*******************
	 * initialisations *
	 *******************/
void initialisations(){
	
	initMenu();				// On initialise l'�cran LCD
	initBluetooth();	// On initialise le bluetooth
	initTimer1();			// On initialise le timer qui met � jour les valeurs des capteurs
	initSensors();		// On initialise les diff�rents capteurs
	
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
	TIM_ConfigStruct.PrescaleValue = 25000;	// pr�cision 1ms

	TIM_MatchConfigStruct.MatchChannel = 2;
	TIM_MatchConfigStruct.IntOnMatch = ENABLE;
	TIM_MatchConfigStruct.ResetOnMatch = ENABLE;
	TIM_MatchConfigStruct.StopOnMatch = DISABLE;
	TIM_MatchConfigStruct.ExtMatchOutputType = TIM_EXTMATCH_NOTHING;
	TIM_MatchConfigStruct.MatchValue = 100;	// par d�faut

	TIM_Init(LPC_TIM1, TimerCounterMode, &TIM_ConfigStruct);
	TIM_ConfigMatch(LPC_TIM1, &TIM_MatchConfigStruct);
	
	NVIC_EnableIRQ(TIMER1_IRQn);	// On active la fonction d'interruption
}

	/***************
	 * startTimer1 *
	 ***************/
void startTimer1(uint32_t duree){

	TIM_UpdateMatchValue(LPC_TIM1, 2, duree);	// On met � jour la dur�e du timer
	TIM_Cmd(LPC_TIM1, ENABLE);								// On d�marre le compteur

	flagTIM1 = true;													// On l�ve le flag du timer 1
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
	
	bool bp = ((GPIO_ReadValue(2)>>10)&0x1);	// On r�cup�re l'�tat de la broche du bouton 2 (p0.12)
	unsigned int i;		// Initialisation de la valeur permettant de tempor�ser et donc d'�viter les rebonds
	
	if(bp != oldMaintienBouton){	// S'il l'on d�tecte un changement de front
		
		for(i = 0; i < 1000; ++i){}
		if(bp){	// Si on d�tecte un front montant
			
			lcd_clear(Blue);						// On repeint l'�cran en bleu
			numMenu = (numMenu + 1)%3;	// On incr�mente la variable du menu
			//jouerMelodie();	// On lance la m�lodie
		}
	}
	
	//jouerBuzzer();		// On joue la note 
	oldMaintienBouton = bp;	// On sauvegarde l'ancien etat du outon
  getRainSensor();				// On v�rifie l'�tat du capteur d'eau (p0.11)
}

char* concatene(char caractere, uint32_t value){
	
	// On concat�ne le carac�re suivis d'un foat pr�cis au dixi�mes, le tous encadr� d'*
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

	if(!flagTIM1){	// Si l'interruption du timer 1 � �t� r�alis�e, 
		
		startTimer1(50); // On d�marre le timer pour une dur�e de 50 ms
		if(sensorToUpdate == 0){
			
			getTempSensor();	// On met � jour la valeur du capteur de temp�rature
			sendMessage(concatene('T', temperature));	// On concat�ne et envoie les informations au t�l�phone
		}
		else if(sensorToUpdate == 1){
			
			getLightSensor();	// On met � jour la valeur du capteur de luminosit�
			setDayNightIcon();	// On met a jour le apteur de jour/nuit
			sendMessage(concatene('L', luminosite));	// On concat�ne et envoie les informations � l'application
		}
		else if(sensorToUpdate == 2){
			
			co2 = 30;	// Valeur par d�faut en attente de l'impl�mentation du capteur de CO2
			sendMessage(concatene('C', co2));
		}
		else if(sensorToUpdate == 3){
			
			humidite = 50.f;	// Valeur par d�faut en attente de l'impl�mentation du capteur d'humidit�/Temp�rature
			sendMessage(concatene('H', humidite)); 
		}
	}
	
	getWeatherIcon();		// On met � jour l'ic�ne du temps
}

void stationMeteo(){
	
	boutons();		// On r�cup�re les valeurs des boutons
	bluetooth();	// On met � jour ou non les valeurs des capteurs
	menu();				// On affiche l'�cran LCD
}
