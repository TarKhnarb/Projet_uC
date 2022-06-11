#include "capteurs.h"

void initSensors(){
	
	initTempSensor();
	initLightSensor();
	ADC_Init(LPC_ADC, 100000);
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
	
	ADC_ChannelCmd (LPC_ADC, 4, ENABLE);
	ADC_StartCmd(LPC_ADC, ADC_START_NOW);
	while(!ADC_ChannelGetStatus(LPC_ADC, 4, 1)){}
	
	tmp = ADC_ChannelGetData(LPC_ADC, 4);
	ADC_ChannelCmd (LPC_ADC, 4, DISABLE);
		
	a +=((8192)*8-1)/(tmp-1); //abs(((6300.f-(float)tmp)*10000.f/(float)(tmp)));
	temperature = 1.f/(log(a/100.f)/4275.f+1.f/298.15f)-273.15f-37.f;
		
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
	
	ADC_ChannelCmd (LPC_ADC, 5, ENABLE);
	ADC_StartCmd(LPC_ADC, ADC_START_NOW);
	while(!ADC_ChannelGetStatus(LPC_ADC, 5, 1)){}
	
	light=ADC_ChannelGetData(LPC_ADC, 5);
		
	ADC_ChannelCmd (LPC_ADC, 5, DISABLE);
		
	luminosite = ((float)light/4095.f)*100.f;
}

void initRainSensor(void){
	
	pluie = false;
}

void getRainSensor(){
	
	bool bp = ((GPIO_ReadValue(2)>>11)&0x1);
	unsigned int i;
	if(bp != oldMaintienBouton2){
		
		for(i = 0; i < 1000; ++i){}
		pluie = !pluie;
	}
	
	oldMaintienBouton2 = bp;
}
	