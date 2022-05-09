//===========================================================//
// Projet Micro - SNUM1 - ENSSAT														 //
//===========================================================//
// File                : Programme de d�part
// Hardware Environment: Open1768	
// Build Environment   : Keil �Vision
//===========================================================//

#include "affichagelcd.h"
#include "menuLCD.h"
#include "globaldec.h" // fichier d�claration variables globales
#include "bouton.h"
#include "CAN.h"
#include "emetteur.h"

//PINSEL_CFG_Type			PWM_Pin_Config; // Structure Pinsel -> click droit goto definition
	
//===========================================================//
// Function: Main
//===========================================================//
int main(void){

	
	  initMenu();
		//initTempSensor();
		initBluetooth();
		
    while(1){

			//getTempSensor();
			BP();
			BP2();
			menu();

			
			if(flagBluetooth){
				
				flagBluetooth = false;
			}
			
		}	
}

//---------------------------------------------------------------------------------------------	
#ifdef  DEBUG
void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif
