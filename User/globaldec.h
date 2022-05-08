#include <stdint.h>
#include <stdbool.h>

#include "constantes.h"
#include "lpc17xx_i2c.h"

//__________ affichagelcd.h __________

char chaine[30]; // buffer pour l'affichage sur le LCD
uint16_t touch_x, touch_y ;

//__________ menu.h __________

unsigned char numMenu;

//__________ bouton.h __________
bool maintienBouton = false;
bool maintienBouton2 = false;

bool oldMaintienBouton = false;
bool oldMaintienBouton2 = false;

//__________ CAN.h __________
uint16_t temperature;

//__________ emmeteur.h __________
bool flagTIM1 = false;
