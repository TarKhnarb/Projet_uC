#include "capteurs.h"

void initTempSensor(void){
	
		// P1.31:
	
	PINSEL_CFG_Type			configPin; 
	PCONP_ |= (1 << 12); //AD0 
	configPin.Funcnum 	 = 3;
	configPin.OpenDrain = PINSEL_PINMODE_NORMAL;
	configPin.Pinmode 	 = PINSEL_PINMODE_NORMAL; //output
	configPin.Portnum 	 = 1;
	configPin.Pinnum 	 = 31;
	PINSEL_ConfigPin(&configPin);
	
	
	
	ADC_Init(LPC_ADC, 100000);
	ADC_ChannelCmd (LPC_ADC, 5, ENABLE);
}

void getTempSensor(void){
	
	uint16_t tmp;
	float a=0.f;
	ADC_StartCmd(LPC_ADC, ADC_START_NOW);
	while(!ADC_ChannelGetStatus(LPC_ADC, 5, 1)){}
	
	tmp = ADC_ChannelGetData(LPC_ADC, 5);
		
	a += abs((float)((1023-tmp)*10000/tmp));
	temperature = 1.f/(log(a/10000.f)/3975.f+1.f/298.15f)-273.15f;
		
}
