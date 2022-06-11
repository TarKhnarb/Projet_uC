#include "affichagelcd.h"
#include "touch\ili_lcd_general.h"
#include "touch\lcd_api.h"
#include "touch\touch_panel.h"
#include "global.h"
#include <stdio.h>
#include <string.h>

/*
 * initMenu()
 * Initialise l'écran lcd
 */
void initMenu(void);

/*
 * menu()
 * Gère les différents menu sur l'écran LCD
 */
void menu(void);

/*
 * printPixelArt():
 *		temps: uint8_t, variable correspondant au temps caculé par le programme
 *		x: 		 unsigned int, cooédonée x (haut gauche) où placer l'icône
 *		y: 		 unsigned int, cooédonée y (haut gauche) où placer l'icône
 */		
void printPixelArt(uint8_t temps, unsigned x, unsigned y);

	// Fonction utilisées par les fonctions précedentes :

/*
 * subPrintOixelArt():
 *		pxl:  unsigned short[5][5], tableau contenant l'icône
 *		x: 		unsigned int, cooédonée x (haut gauche) où placer l'icône
 *		y: 		unsigned int, cooédonée y (haut gauche) où placer l'icône
 *		e: 		unsigned int, indice d'agrandissement
 * Permets de créer une homotétie de l'icône choisie au coordonnées souhaitées
 */
 