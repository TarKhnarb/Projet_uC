#include <stdint.h>
#include <stdbool.h>

#include "constantes.h"
#include "lpc17xx_i2c.h"

//__________ buzzer.h_________
// Ports:
// 	p0.26

uint8_t cpt_note;
bool flag_note;
uint8_t note;
uint16_t cpt_duree;
bool flag_duree;
uint8_t index_note;
bool noteSonne;

uint8_t tab_note[16];
int tab_duree_note[16];

double frequencesNotes[12] = { 32.7f, 34.64f, 36.70f, 38.89f, 41.20f, 43.65f, 46.24f, 48.99f, 51.91f, 55.f, 58.27f, 61.73f};

//__________ affichagelcd.h __________
// Ports:
// 	p06-9
//	p0.19-23
//	p1.23-25
// 	p2.0-7

char chaine[30]; // buffer pour l'affichage sur le LCD
uint16_t touch_x, touch_y ;

//__________ menuLCD.h __________
uint8_t numMenu;
uint8_t temps;
uint8_t jourNuit;

//__________ application.h __________
uint8_t sensorToUpdate;
bool oldMaintienBouton = true;
bool oldMaintienBouton2 = true;

//__________ capteur.h __________
// Ports:
//	p1.30 -> température
//	p1.31 -> lumoinosité
// 	p2.11 -> pluie
float temperature;
float luminosite;
float co2;
float humidite;
bool pluie;

//__________ bluetooth.h __________
// Ports:
//	p0.2 -> Tx
//	p0.3 - Rx
//  uart0
// 	Timer 1 MR2
bool flagBluetooth = false;
bool flagTIM1 = false;
char stringToSend[7];

//__________ menuLCD.h __________
const unsigned short BF = 0x1336;	// pixel Bleu Fonc�
const unsigned short BC = 0x38DA;	// pixel Bleu Clair
const unsigned short GF = 0xAAEA; // pixel Gris Fonc�
const unsigned short GC = 0xDD9D; // pixel Gris Clair
const unsigned short NN = 0x0000;	// pixel Noir Noir
const unsigned short BB = 0xFFFF; // pixel Blanc Blanc
const unsigned short JF = 0xFE23; // pixel Jaune Fonc�

unsigned short LUNE[5][5] = 
{{BF, BF, GF, GF, BF},
 {BF, GF, BF, BF, BF},
 {BF, GF, BF, BF, BF},
 {BF, GF, BF, BF, BF},
 {BF, BF, GF, GF, BF}
};

unsigned short SOLEIL[5][5] = 
{{BC, BC, BC, BC, BC},
 {BC, BC, JF, BC, BC},
 {BC, JF, JF, JF, BC},
 {BC, BC, JF, BC, BC},
 {BC, BC, BC, BC, BC},
};

unsigned short NUAGE[5][5] = 
{{BC, BC, BC, BC, BC},
 {BC, BC, GC, GC, BC},
 {BC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC},
 {BC, BC, BC, BC, BC},
};

unsigned short PLUIE[5][5] = 
{{GC, GC, BF, GC, GC},
 {GC, GC, BF, GC, GC},
 {GC, BF, BF, BF, GC},
 {GC, BF, BF, BF, GC},
 {GC, GC, BF, GC, GC},
};

unsigned short NEIGE[5][5] =
{{GC, GC, GC, GC, GC},
 {GC, GC, BB, GC, GC},
 {GC, BB, BB, BB, GC},
 {GC, GC, BB, GC, GC},
 {GC, GC, GC, GC, GC},
};
