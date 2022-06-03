#include "capteurs.h"

void initSensors(){
	
	initTempSensor();
	initLightSensor();
	initMoistureSensor();
	ADC_Init(LPC_ADC, 100000);
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
	
	ADC_ChannelCmd (LPC_ADC, 2, ENABLE);
	ADC_StartCmd(LPC_ADC, ADC_START_NOW);
	while(!ADC_ChannelGetStatus(LPC_ADC, 2, 1)){}
	
	tmp = ADC_ChannelGetData(LPC_ADC, 2);
	ADC_ChannelCmd (LPC_ADC, 2, DISABLE);
		
	a += abs(((1023.f-(float)tmp)*10000.f/(float)tmp));
	temperature = 1.f/(log(a/10000.f)/3975.f+1.f/298.15f)-273.15f;
		
}
void initLightSensor(){
	

	
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
	
	ADC_ChannelCmd (LPC_ADC, 5, ENABLE);
	ADC_StartCmd(LPC_ADC, ADC_START_NOW);
	while(!ADC_ChannelGetStatus(LPC_ADC, 5, 1)){}
	
	light=ADC_ChannelGetData(LPC_ADC, 5);
		
	ADC_ChannelCmd (LPC_ADC, 5, DISABLE);
		
	luminosite=((float)light/4095.f)*100.f;
}

void initMoistureSensor(){
	// P0.24:
	
	PINSEL_CFG_Type			configPin; 
	PCONP_ |= (1 << 12); //AD0 
	configPin.Funcnum 	 = 2;
	configPin.OpenDrain = PINSEL_PINMODE_NORMAL;
	configPin.Pinmode 	 = PINSEL_PINMODE_NORMAL; //output
	configPin.Portnum 	 = 0;
	configPin.Pinnum 	 = 24;
	PINSEL_ConfigPin(&configPin);
}

void getMoistureSensor(){
	ADC_ChannelCmd (LPC_ADC, 1, ENABLE);
	ADC_StartCmd(LPC_ADC, ADC_START_NOW);
	while(!ADC_ChannelGetStatus(LPC_ADC, 1, 1)){}
}

void initRainSensor(void){
	
	pluie = false;
}

void getRainSensor(){
	
	bool bp = ((GPIO_ReadValue(2)>>11)&0x1);
	unsigned int i;
	if(bp != oldMaintienBouton2){
		
		for(i = 0; i < 1000; ++i){}
		if(bp){
			
			// Instruction
			
		}
		pluie = !pluie;
	}
	
	oldMaintienBouton2 = bp;
}
	