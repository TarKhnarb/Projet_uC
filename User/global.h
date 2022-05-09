//===========================================================//
// Projet Micro - SNUM1 - ENSSAT														 //
//===========================================================//
#include <stdint.h>
#include <stdbool.h>

#include "constantes.h"
#define PCONP_ *(unsigned long *)0x400FC0C4

extern char chaine[30]; // buffer pour l'affichage sur le LCD
extern uint16_t touch_x, touch_y ;

//__________ menu.h __________
extern unsigned char numMenu;

//__________ bouton.h __________
extern bool maintienBouton;
extern bool maintienBouton2;

extern bool oldMaintienBouton;
extern bool oldMaintienBouton2;

//__________ CAN.h __________
extern uint16_t temperature;

//__________ emetteur.h __________
extern bool flagBluetooth;
extern bool flagTIM1;
