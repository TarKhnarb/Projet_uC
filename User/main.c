//===========================================================//
// Projet Micro - SNUM1 - ENSSAT														 //
//===========================================================//
// File                : Programme de départ
// Hardware Environment: Open1768	
// Build Environment   : Keil µVision
//===========================================================//
#include <stdio.h>

#include "lpc17xx_libcfg_default.h"
#include "lpc17xx_gpio.h"						// Fonctions et Structures GPIO
#include "lpc17xx_pinsel.h"					// Fonctions et Structures PINSEL
#include "lpc17xx_timer.h"					// Fonctions et Structures TIMER
#include "lpc17xx_uart.h"						// Fonctions et Structures UART
#include "lpc17xx_exti.h"						// Fonctions et Structures EXTINT
#include "lpc17xx_nvic.h"						// Fonctions et Structures NVIC
																		// Ajouter ceux dont vous avez besoin en plus

#include "touch\ili_lcd_general.h"
#include "touch\lcd_api.h"
#include "touch\touch_panel.h"

#include "affichagelcd.h"
#include "menuLCD.h"

#include "globaldec.h" // fichier déclaration variables globales

PINSEL_CFG_Type			PWM_Pin_Config; // Structure Pinsel -> click droit goto definition
	
//===========================================================//
// Function: Main
//===========================================================//
int main(void)
{	  
//----------------------------------------------------------------	
// Exemple affichage LCD 4 carrés couleur et chaine de caractère
//----------------------------------------------------------------
	
	  initMenu();
	  /*sprintf(chaine,"Ceci est un exemple      ");
	  LCD_Write_String (32,30,chaine,White,Blue);
	  LCD_Draw_Rectangle(10,60,110,110,2,1,Black,Yellow);
	  LCD_Draw_Rectangle(120,60,110,110,2,1,Black,Green);
	  LCD_Write_String (32,30,chaine,White,Blue);
	  LCD_Draw_Rectangle(10,170,110,110,2,1,Black,Blue);
	  LCD_Draw_Rectangle(120,170,110,110,2,1,Black,Red);*/
		
	  
//----------------------------------------------------------------	
// Exemple utilisation structure de PINSEL avec librairie
//----------------------------------------------------------------
		// Output PINs Selection
		// P1.28: MAT0.0		3rd functionality
	
		PWM_Pin_Config.Funcnum 	 = 3;
		PWM_Pin_Config.OpenDrain = PINSEL_PINMODE_NORMAL;
		PWM_Pin_Config.Pinmode 	 = PINSEL_PINMODE_NORMAL; //output
		PWM_Pin_Config.Portnum 	 = 1;
		PWM_Pin_Config.Pinnum 	 = 28;

		PINSEL_ConfigPin(&PWM_Pin_Config);
	
//----------------------------------------------------------------	
// Boucle infinie
//----------------------------------------------------------------

    while(1)
		{
			menu();
		}
		
		
		
		
	}

//---------------------------------------------------------------------------------------------	
#ifdef  DEBUG
void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif
