#include "application.h"

	/*******************
	 * initialisations *
	 *******************/
void initialisations(){
	
	initMenu();
	initBluetooth();
	initTimer1();
}

void boutons(){
	
	BP();
	//BP2();
}

char* concatene(char caractere, uint32_t value){
	
	sprintf(stringToSend, "*%c%.1f*", caractere, (float)value);
	
	return &(stringToSend[0]);
}

void bluetooth(){

	if(!flagTIM1){
		
		startTimer1(2000000);
		switch(sensorToUpdate){
			
			case 0:	// température
				temperature = (rand()%10) + 10;
				sendMessage(concatene('T', temperature));
				break;
			
			case 1:	// luminosité
				luminosite = (rand()%90) + 10;
				sendMessage(concatene('L', luminosite));
				break;
			
			case 2:	// CO2
				co2 = (rand()%90) + 10;
				sendMessage(concatene('C', co2));
				break;
			
			case 3:	// Humidité
				humidite = (rand()%90) + 10;
				sendMessage(concatene('H', humidite)); 
				break;
			
		 default:
				break;
		}
	}
	
	if(flagBluetooth){
			
		flagBluetooth = false;
	}
}

void stationMeteo(){
	
	boutons();
	bluetooth();
	menu();
}
