#include "I2C.h"

void initI2C0(){
        
	PINSEL_CFG_Type	configSDA;
	PINSEL_CFG_Type	configSCL;
	
	flagCO2 = false;
	
	configSDA.Portnum = 0;
	configSDA.Pinnum = 27;
	configSDA.Funcnum = 1;
	configSDA.Pinmode = PINSEL_PINMODE_PULLDOWN;
	configSDA.OpenDrain = PINSEL_PINMODE_OPENDRAIN;
	PINSEL_ConfigPin(&configSDA);
	
	configSCL.Portnum = 0;
	configSCL.Pinnum = 28;
	configSCL.Funcnum = 1;
	configSCL.Pinmode = PINSEL_PINMODE_PULLDOWN;
	configSCL.OpenDrain = PINSEL_PINMODE_OPENDRAIN;
	PINSEL_ConfigPin(&configSCL);
	
	I2C_Init(LPC_I2C0, 400000);
	
	I2C_Cmd(LPC_I2C0, ENABLE);
	
	// On initialise le capteur en lui envoyant une information
	co2Trame[0] = 32;	// MeasureTest (0x20..) p.9 docu
	co2Trame[1] = 03;	// InitAirQuality (0x20..)
	ecrire(0x58, co2Trame, 2);
}

void ecrire(uint32_t adresse, uint8_t *data, uint32_t length){
        
	I2C_M_SETUP_Type I2CSetup;
	I2CSetup.sl_addr7bit = adresse;
	I2CSetup.tx_data = data;
	I2CSetup.tx_length = length;
	I2CSetup.rx_data = NULL;
	I2CSetup.rx_length = 0;
	I2CSetup.retransmissions_max = 3;
	
	I2C_MasterTransferData(LPC_I2C0, &I2CSetup, I2C_TRANSFER_POLLING);
}

void lire(uint32_t adresse, uint8_t *data, uint32_t length, uint8_t *receivedData, uint32_t receivedLength){
        
	I2C_M_SETUP_Type I2CSetup;
	I2CSetup.sl_addr7bit = adresse;
	I2CSetup.rx_data = receivedData;
	I2CSetup.rx_length = receivedLength;
	I2CSetup.tx_data = data;
	I2CSetup.tx_length = length;
	I2CSetup.retransmissions_max = 3;
	
	I2C_MasterTransferData(LPC_I2C0, &I2CSetup, I2C_TRANSFER_POLLING);
}

void I2C0_IRQHandler(){
	
	while(!I2C_MasterTransferComplete(LPC_I2C0)){
		
		I2C_MasterHandler(LPC_I2C0);
	}
	
	switch(co2Trame[1]){
		
		
		case 0x03:
			break;
		
		case 0x08:
			if(flagCO2){
				
				flagCO2 = false;
				CO2_co2eq=(CO2_data[0]<<4)|CO2_data[1];
				CO2_voc=(CO2_data[3]<<4)|CO2_data[4];
				
				if(CO2_voc>=3525){
					VOC=(CO2_voc-3525)*32+11110;
				}
				
				else if(CO2_voc>=2008){
					VOC=(CO2_voc-2008)*6+2008;
				}
				
				else{
					VOC=CO2_voc;
				}
				
				
				if(CO2_co2eq>=3685){
					CO2_EQ=(CO2_co2eq-3685)*31+17597;
				}
				
				else if(CO2_co2eq>=2301){
					CO2_EQ=(CO2_co2eq-2301)*9+5144;
				}
				
				else if(CO2_co2eq>=1079){
					CO2_EQ=(CO2_co2eq-1079)+1479;	
				}	
				
				else{
					CO2_EQ=CO2_co2eq+400;	
				}

			}
			else{
				
			}
			break;
	}
}

void test(){
	
	if (flagCO2){
		if(flagCO2init < 15){
			flagCO2init++;
		}
		else{
			
			
		}
		
		flagCO2Sensor=0;
	}
	
	if(flagConvertion==1){
		flagConvertion=0;
		sprintf(AH, "%f", abs_hum);
		CO2_AH[0]=(uint8_t)((int)strtok(AH,"."));
		CO2_AH[1]=(uint8_t)(((int)strtok(NULL,"."))*2.55);
		CO2_AH[2]=CO2_AH[0]+CO2_AH[1];//have to be modifie ?
		
		CO2_command[1]=Set_humidity ;
		CO2_capteur.tx_data=CO2_AH;
		CO2_capteur.tx_length=3;
				
		CO2_capteur.rx_data=NULL;
		CO2_capteur.rx_length=0;
		I2C_MasterTransferData(LPC_I2C0,&CO2_capteur,I2C_TRANSFER_INTERRUPT);
	}
}
