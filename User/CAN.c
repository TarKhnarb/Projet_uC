#include "CAN.h"

void initTempSensor(void){
	
	// Output PINs Selection
		// P0.23: MAT0.0		3rd functionalit
	PINSEL_CFG_Type			PWM_Pin_Config; // Structure Pinsel -> click droit goto definition

	PWM_Pin_Config.Funcnum 	 = 1;
	PWM_Pin_Config.OpenDrain = PINSEL_PINMODE_NORMAL;
	PWM_Pin_Config.Pinmode 	 = PINSEL_PINMODE_NORMAL; //output
	PWM_Pin_Config.Portnum 	 = 0;
	PWM_Pin_Config.Pinnum 	 = 23;
	PINSEL_ConfigPin(&PWM_Pin_Config);
	
	PCONP_ |= (1 << 12);
	
	ADC_Init(LPC_ADC, 100000);
	ADC_ChannelCmd (LPC_ADC, 0, ENABLE);
	ADC_StartCmd(LPC_ADC, ADC_START_NOW);
	
}

void getTempSensor(void){
	
	temperature = ADC_ChannelGetStatus(LPC_ADC, 0, ENABLE);
	//uint16_t tmp 
	//temperature = ADC_ChannelGetData(LPC_ADC, 0);
	
	//int a = (float)(1023-a)*10000/a;
	//temperature = 1/(log(tmp/10000)/(3975)+1/298.15)-273.15;
	
}
