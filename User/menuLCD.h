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

void printPixelArt(uint8_t temps, unsigned int x, unsigned int y);

