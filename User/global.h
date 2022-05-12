//===========================================================//
// Projet Micro - SNUM1 - ENSSAT														 //
//===========================================================//
#include <stdint.h>
#include <stdbool.h>

#include "constantes.h"
#define PCONP_ *(unsigned long *)0x400FC0C4

//__________ affichagelcd.h __________
extern char chaine[30]; // buffer pour l'affichage sur le LCD
extern uint16_t touch_x, touch_y ;

//__________ menu.h __________
extern uint8_t numMenu;

//__________ bouton.h __________
extern bool maintienBouton;
extern bool maintienBouton2;

extern bool oldMaintienBouton;
extern bool oldMaintienBouton2;

//__________ capteurs.h __________
extern uint16_t temperature;
extern uint16_t luminosite;
extern uint16_t co2;
extern uint16_t humidite;

//__________ bluetooth.h __________
extern bool flagBluetooth;
extern bool flagTIM1;
extern char stringToSend[7];

//__________ application.h __________
extern uint8_t sensorToUpdate;
