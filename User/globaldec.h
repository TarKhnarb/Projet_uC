#include "constantes.h" // fichier contenant toutes les constantes du projet
#include <stdint.h>
#include "lpc17xx_i2c.h"

//__________ affichagelcd.h __________

char chaine[30]; // buffer pour l'affichage sur le LCD
uint16_t touch_x, touch_y ;

//__________ menu.h __________

unsigned char numMenu;
unsigned char maintienBouton = 0;
unsigned char oldMaintienBouton = 0;

//__________ CAN.h __________

uint16_t temperature;