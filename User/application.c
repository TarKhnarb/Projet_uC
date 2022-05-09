#include "application.h"

	/*******************
	 * initialisations *
	 *******************/
void initialisation(){
	
	//initTempSensor();
	initBluetooth();
	initMenu();
}

void boutons(){
	
	BP();
	BP2();
}

void bluetooth(){

	
}

void stationMeteo(){
	
	boutons();
	bluetooth();
	
	if(flagBluetooth){
			
			flagBluetooth = false;
	}	
		
		menu();
}