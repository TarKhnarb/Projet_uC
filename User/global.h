//===========================================================//
// Projet Micro - SNUM1 - ENSSAT														 //
//===========================================================//
#include <stdint.h>
#include <stdbool.h>

#include "constantes.h"
#define PCONP_ *(unsigned long *)0x400FC0C4

//__________ buzzer.h_________
int buzzer;

extern unsigned int cpt_note;
extern bool flag_note;
extern unsigned int note;
extern unsigned int cpt_duree;
extern bool flag_duree;
extern unsigned int index_note;
extern bool noteSonne;

extern char tab_note[16];
extern int tab_duree_note[16];
extern double frequencesNotes[12];

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

extern unsigned short LUNE[21][21];
extern unsigned short SOLEIL[21][21];
extern unsigned short NUAGE[21][21];
extern unsigned short PLUIE[21][21];
extern unsigned short NEIGE[21][21];
