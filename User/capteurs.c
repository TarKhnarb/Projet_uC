#include "capteurs.h"

void initTempSensor(void){
	
		// P1.31:
	PINSEL_CFG_Type			configPin; 

	configPin.Funcnum 	 = 2;
	configPin.OpenDrain = PINSEL_PINMODE_NORMAL;
	configPin.Pinmode 	 = PINSEL_PINMODE_NORMAL; //output
	configPin.Portnum 	 = 0;
	configPin.Pinnum 	 = 31;
	PINSEL_ConfigPin(&configPin);
	
	PCONP_ |= (1 << 12); //AD0 
	
	ADC_Init(LPC_ADC, 100000);
	ADC_ChannelCmd (LPC_ADC, 5, ENABLE);
}

void getTempSensor(void){
	
	uint16_t tmp;
	float a;
	ADC_StartCmd(LPC_ADC, ADC_START_NOW);
	while(!ADC_ChannelGetStatus(LPC_ADC, 5, 1)){}
	
	temperature = ADC_ChannelGetData(LPC_ADC, 5);
		/*
	a = (float)(1023-tmp)*10000/tmp;
	temperature = 1/(log(a/10000)/(3975)+1/298.15)-273.15;
		*/
}
