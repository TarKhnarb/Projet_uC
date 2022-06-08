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
extern unsigned char numMenu;
extern unsigned char temps;
extern unsigned char jourNuit;

//__________ bouton.h __________
extern bool maintienBouton;
extern bool maintienBouton2;

extern bool oldMaintienBouton;
extern bool oldMaintienBouton2;

//__________ capteurs.h __________
extern float temperature;
extern float luminosite;
extern float co2;
extern float humidite;
extern bool pluie;


//__________ bluetooth.h __________
extern bool flagBluetooth;
extern bool flagTIM1;
extern char stringToSend[7];

//__________ application.h __________
extern uint8_t sensorToUpdate;


//__________ menuLCD.h __________
extern const unsigned short BF;
extern const unsigned short GF;
extern const unsigned short GC;
extern const unsigned short NN;

extern unsigned short LUNE[11][11];
extern unsigned short SOLEIL[11][11];
extern unsigned short NUAGE[11][11];
extern unsigned short PLUIE[11][11];
extern unsigned short NEIGE[11][11];
