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
		
	initialisations();	// Appel des initialisations de l'application
	
	while(1){
		
		stationMeteo();	// On exécute notre application
	}	
}

//---------------------------------------------------------------------------------------------	
#ifdef  DEBUG
	void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif
