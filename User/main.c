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
#include "capteurs.h"
#include "bluetooth.h"

//PINSEL_CFG_Type			PWM_Pin_Config; // Structure Pinsel -> click droit goto definition
	
//===========================================================//
// Function: Main
//===========================================================//
int main(void){
		
		//__________ menu.h __________
	initMenu();	// Initialisation du menu
	
		//__________ ADC.h __________
	//initTempSensor();	// Initialisation du capteur de température
	
		//__________ emetteur.h __________
	initBluetooth();	// Initialisation du bluetooth
	
	while(1){

		//getTempSensor();	// Récupère la valeur du capteur
		
		BP(); // Bouton de changement de menu
		
		BP2();	// BP test de l'envoi de données à l'appli
		if(flagBluetooth){
			
			flagBluetooth = false;
		}	
		
		menu();
	}	
}

//---------------------------------------------------------------------------------------------	
#ifdef  DEBUG
	void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif
