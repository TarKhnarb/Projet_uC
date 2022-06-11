
#include "capteurs.h"

void initSensors(){
	
	initTempSensor();	
	initLightSensor();
	ADC_Init(LPC_ADC, 100000);	// On initialise à la fréquence conversion de l'adc
	initRainSensor();
}
	
void initTempSensor(){
	
		// P0.25:
	
	PINSEL_CFG_Type			configPin; 
	PCONP_ |= (1 << 12); //AD0 
	configPin.Funcnum 	 = 2;
	configPin.OpenDrain = PINSEL_PINMODE_NORMAL;
	configPin.Pinmode 	 = PINSEL_PINMODE_NORMAL; //output
	configPin.Portnum 	 = 0;
	configPin.Pinnum 	 = 25;
	PINSEL_ConfigPin(&configPin);
}
void getTempSensor(){
	
	uint16_t tmp;
	float a=0.f;
	
	ADC_ChannelCmd (LPC_ADC, 2, ENABLE);	// On active la lecture sur le chanel du capteur
	ADC_StartCmd(LPC_ADC, ADC_START_NOW);	// On commence la conversion
	while(!ADC_ChannelGetStatus(LPC_ADC, 2, 1)){}	// On attend de lire la valeur du capteur
	
	tmp = ADC_ChannelGetData(LPC_ADC, 2);	// On récupère la valeur du capteur
	ADC_ChannelCmd (LPC_ADC, 2, DISABLE);	// On désactive la lecture sur le chanel du capteur
		
	a += abs(((5.5f-(float)tmp)*10000.f/(float)(tmp+1.f)));
	temperature = 1.f/(log(a/10000.f)/3975.f+1.f/298.15f)-273.15f; // On converti la valeur recu
		
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
	
	light = ADC_ChannelGetData(LPC_ADC, 5); 	// On récupère la valeur du capteur
		
	ADC_ChannelCmd (LPC_ADC, 5, DISABLE);	// On désactive la lecture sur le chanel du capteur
		
	luminosite = ((float)light/4095.f)*100.f; // On converti la valeur recu
}

void initRainSensor(void){
	
	pluie = false;	// On initialise la variable de pluie à faux
}

void getRainSensor(){
	
	bool bp = ((GPIO_ReadValue(2)>>11)&0x1);	// On li la valeur de la broche du bouton 1 (p2.11)
	unsigned int i;
	if(bp != oldMaintienBouton2){	// Si on détecte un front 
		
		for(i = 0; i < 1000; ++i){}	// On évite les rebonds
		pluie = !pluie;	// On inverse le booléen de pluie
	}
	
	oldMaintienBouton2 = bp;
}
	