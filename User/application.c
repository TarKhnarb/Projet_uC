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
		
		startTimer1(2); // 2000	// 2s
		if(sensorToUpdate == 0){
				
				// température
			temperature = 10;//(rand()%10) + 10;
			sendMessage(concatene('T', temperature));
		}
		else if(sensorToUpdate == 1){
			// luminosité
			luminosite = 20;//(rand()%90) + 10;
			sendMessage(concatene('L', luminosite));
		}
		else if(sensorToUpdate == 2){
			// CO2
			co2 = 30;//(rand()%90) + 10;
			sendMessage(concatene('C', co2));
		}
		else if(sensorToUpdate == 3){
			// Humidité
			humidite = 40;//(rand()%90) + 10;
			sendMessage(concatene('H', humidite)); 
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
