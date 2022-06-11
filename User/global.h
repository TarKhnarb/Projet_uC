//===========================================================//
// Projet Micro - SNUM1 - ENSSAT														 //
//===========================================================//
#include <stdint.h>
#include <stdbool.h>

#include "constantes.h"
#define PCONP_ *(unsigned long *)0x400FC0C4

//__________ buzzer.h_________

extern uint8_t cpt_note;
extern bool flag_note;
extern uint8_t note;
extern uint16_t cpt_duree;
extern bool flag_duree;
extern uint8_t index_note;
extern bool noteSonne;

extern uint8_t tab_note[16];
extern int tab_duree_note[16];
extern double frequencesNotes[12];

//__________ affichagelcd.h __________
extern char chaine[30]; // buffer pour l'affichage sur le LCD
extern uint16_t touch_x, touch_y ;

//__________ menu.h __________
extern uint8_t numMenu;
extern uint8_t temps;
extern uint8_t jourNuit;

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

extern unsigned short LUNE[5][5];
extern unsigned short SOLEIL[5][5];
extern unsigned short NUAGE[5][5];
extern unsigned short PLUIE[5][5];
extern unsigned short NEIGE[5][5];

