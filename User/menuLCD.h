#include "affichagelcd.h"
#include "touch\ili_lcd_general.h"
#include "touch\lcd_api.h"
#include "touch\touch_panel.h"
#include "global.h"
#include <stdio.h>
#include <string.h>

/*
 * initMenu()
 * Initialise l'�cran lcd
 */
void initMenu(void);

/*
 * menu()
 * G�re les diff�rents menu sur l'�cran LCD
 */
void menu(void);

/*
 * printPixelArt():
 *		temps: uint8_t, variable correspondant au temps cacul� par le programme
 *		x: 		 unsigned int, coo�don�e x (haut gauche) o� placer l'ic�ne
 *		y: 		 unsigned int, coo�don�e y (haut gauche) o� placer l'ic�ne
 */		
void printPixelArt(uint8_t temps, unsigned x, unsigned y);

	// Fonction utilis�es par les fonctions pr�cedentes :

/*
 * subPrintOixelArt():
 *		pxl:  unsigned short[5][5], tableau contenant l'ic�ne
 *		x: 		unsigned int, coo�don�e x (haut gauche) o� placer l'ic�ne
 *		y: 		unsigned int, coo�don�e y (haut gauche) o� placer l'ic�ne
 *		e: 		unsigned int, indice d'agrandissement
 * Permets de cr�er une homot�tie de l'ic�ne choisie au coordonn�es souhait�es
 */
 