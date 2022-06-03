#include "application.h"

	/*******************
	 * initialisations *
	 *******************/
void initialisations(){
	
	initMenu();
	initBluetooth();
	initTimer1();
	initSensors();
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
		
		startTimer1(500); // 2000	// 2s
		if(sensorToUpdate == 0){
			
			getTempSensor();
			sendMessage(concatene('T', temperature));
		}
		else if(sensorToUpdate == 1){
			
			getLightSensor();
			sendMessage(concatene('L', luminosite));
		}
		else if(sensorToUpdate == 2){
			
			co2 = 30;
			sendMessage(concatene('C', co2));
		}
		else if(sensorToUpdate == 3){
			
			getMoistureSensor();
			sendMessage(concatene('H', humidite)); 
		}
		else if(sensorToUpdate == 4){
			
			getRainSensor();
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
