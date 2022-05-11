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
bool maintienBouton;
bool maintienBouton2;

bool oldMaintienBouton = true;
bool oldMaintienBouton2 = true;

//__________ capteur.h __________
uint16_t temperature;
uint16_t luminosite;
uint16_t co2;
uint16_t humidite;

//__________ bluetooth.h __________
bool flagBluetooth = false;
bool flagTIM1 = false;
char stringToSend[7];

//__________ application.h __________
uint8_t sensorToUpdate = 0;
