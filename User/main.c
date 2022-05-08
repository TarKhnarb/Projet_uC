//===========================================================//
// Projet Micro - SNUM1 - ENSSAT														 //
//===========================================================//
// File                : Programme de départ
// Hardware Environment: Open1768	
// Build Environment   : Keil µVision
//===========================================================//

#include "affichagelcd.h"
#include "menuLCD.h"
#include "globaldec.h" // fichier déclaration variables globales
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
		initTimer0();
		initTimer1();
		
    while(1){

			//getTempSensor();
			menu();
			BP();
			BP2();
		}	
}

//---------------------------------------------------------------------------------------------	
#ifdef  DEBUG
void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif
