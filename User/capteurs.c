
#include "capteurs.h"

void initSensors(){
	
	initTempSensor();	
	initLightSensor();
	ADC_Init(LPC_ADC, 100000);	// On initialise � la fr�quence conversion de l'adc
	initRainSensor();
}
	
void initTempSensor(){
	
		// P1.30:
	
	PINSEL_CFG_Type			configPin; 
	PCONP_ |= (1 << 12); //AD0 
	configPin.Funcnum 	 = 3;
	configPin.OpenDrain = PINSEL_PINMODE_NORMAL;
	configPin.Pinmode 	 = PINSEL_PINMODE_NORMAL; //output
	configPin.Portnum 	 = 1;
	configPin.Pinnum 	 = 30;
	PINSEL_ConfigPin(&configPin);
}
void getTempSensor(){
	
	uint16_t tmp;
	float a=0.f;

	ADC_ChannelCmd (LPC_ADC, 2, ENABLE);	// On active la lecture sur le chanel du capteur
	ADC_StartCmd(LPC_ADC, ADC_START_NOW);	// On commence la conversion
	while(!ADC_ChannelGetStatus(LPC_ADC, 2, 1)){}	// On attend de lire la valeur du capteur
	
	tmp = ADC_ChannelGetData(LPC_ADC, 2);	// On r�cup�re la valeur du capteur
	ADC_ChannelCmd (LPC_ADC, 2, DISABLE);	// On d�sactive la lecture sur le chanel du capteur
		
	a +=((8192)*8-1)/(tmp-1);
	temperature = 1.f/(log(a/100.f)/4275.f+1.f/298.15f)-273.15f-37.f; // On converti la valeur recu
		
}
void initLightSensor(){
	// P1.31
	
	PINSEL_CFG_Type			configPin;
	PCONP_ |= (1 << 12); //AD0 
	configPin.Funcnum 	 = 3;
	configPin.OpenDrain = PINSEL_PINMODE_NORMAL;
	configPin.Pinmode 	 = PINSEL_PINMODE_NORMAL; //output
	configPin.Portnum 	 = 1;
	configPin.Pinnum 	 = 31;
	PINSEL_ConfigPin(&configPin);
}

void getLightSensor(){
	
	uint16_t light;
	
	ADC_ChannelCmd (LPC_ADC, 5, ENABLE); 	// On active la lecture sur le chanel du capteur
	ADC_StartCmd(LPC_ADC, ADC_START_NOW);	// On commence la conversion
	while(!ADC_ChannelGetStatus(LPC_ADC, 5, 1)){}// On attend de lire la valeur du capteur
	
	light = ADC_ChannelGetData(LPC_ADC, 5); 	// On r�cup�re la valeur du capteur
		
	ADC_ChannelCmd (LPC_ADC, 5, DISABLE);	// On d�sactive la lecture sur le chanel du capteur
		
	luminosite = ((float)light/4095.f)*100.f; // On converti la valeur recu
}

void initRainSensor(void){
	
	pluie = false;	// On initialise la variable de pluie � faux
}

void getRainSensor(){
	
	bool bp = ((GPIO_ReadValue(2)>>11)&0x1);	// On li la valeur de la broche du bouton 1 (p2.11)
	unsigned int i;
	if(bp != oldMaintienBouton2){	// Si on d�tecte un front 
		
		for(i = 0; i < 1000; ++i){}	// On �vite les rebonds
		pluie = !pluie;	// On inverse le bool�en de pluie
	}
	
	oldMaintienBouton2 = bp;
}
	