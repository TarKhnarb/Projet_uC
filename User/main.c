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
	//initTempSensor();	// Initialisation du capteur de temp�rature
	
		//__________ emetteur.h __________
	initBluetooth();	// Initialisation du bluetooth
	
	while(1){

		//getTempSensor();	// R�cup�re la valeur du capteur
		
		BP(); // Bouton de changement de menu
		
		BP2();	// BP test de l'envoi de donn�es � l'appli
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
