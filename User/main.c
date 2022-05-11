//===========================================================//
// Projet Micro - SNUM1 - ENSSAT														 //
//===========================================================//
// File                : Programme de départ
// Hardware Environment: Open1768	
// Build Environment   : Keil µVision
//===========================================================//

#include "globaldec.h" // fichier d�claration variables globales
#include "application.h"

//PINSEL_CFG_Type			PWM_Pin_Config; // Structure Pinsel -> click droit goto definition
	
//===========================================================//
// Function: Main
//===========================================================//
int main(void){
		
	initialisations();
	
	while(1){
		
		stationMeteo();
	}	
}

//---------------------------------------------------------------------------------------------	
#ifdef  DEBUG
	void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif
