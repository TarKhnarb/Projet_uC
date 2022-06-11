#include "application.h"

	/*******************
	 * initialisations *
	 *******************/
void initialisations(){
	
	initMenu();
	initBluetooth();
	initTimer1();
	initSensors();
	
	//initBuzzer();
	//initTimer0();
}

void boutons(){
	
	bool bp = ((GPIO_ReadValue(2)>>10)&0x1);
	unsigned int i;
	
	
	if(bp != oldMaintienBouton){
		
		for(i = 0; i < 1000; ++i){}
		if(bp){
			
			lcd_clear(Blue);
			numMenu = (numMenu + 1)%3;
			//jouerMelodie();
		}
	}
	
	//jouerBuzzer();
	oldMaintienBouton = bp;
  getRainSensor();
}

char* concatene(char caractere, uint32_t value){
	
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

	if(!flagTIM1){
		
		startTimer1(50); // 2000	// 2s
		if(sensorToUpdate == 0){
			
			getTempSensor();
			sendMessage(concatene('T', temperature));
		}
		else if(sensorToUpdate == 1){
			
			getLightSensor();
			setDayNightIcon();
			sendMessage(concatene('L', luminosite));
		}
		else if(sensorToUpdate == 2){
			
			co2 = 30;
			sendMessage(concatene('C', co2));
		}
		else if(sensorToUpdate == 3){
			
			humidite = 50.f;
			sendMessage(concatene('H', humidite)); 
		}
	}
	
	getWeatherIcon();
}

void stationMeteo(){
	
	boutons();
	bluetooth();
	menu();
}
