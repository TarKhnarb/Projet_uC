#include <stdint.h>
#include <stdbool.h>

#include "constantes.h"
#include "lpc17xx_i2c.h"

//__________ affichagelcd.h __________

char chaine[30]; // buffer pour l'affichage sur le LCD
uint16_t touch_x, touch_y ;

//__________ menuLCD.h __________
unsigned char numMenu;
unsigned char temps;
unsigned char jourNuit;

//__________ application.h __________
uint8_t sensorToUpdate;

//__________ bouton.h __________
bool oldMaintienBouton = true;
bool oldMaintienBouton2 = true;

//__________ capteur.h __________
float temperature;
float luminosite;
float co2;
float humidite;
bool pluie;

//__________ bluetooth.h __________
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

unsigned short LUNE[11][11] = 
{{BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF},
 {BF, BF, BF, GF, GF, GF, GF, GF, BF, BF, BF},
 {BF, BF, GF, GC, GC, GC, GC, GC, GF, BF, BF},
 {BF, GF, GC, GC, GC, GC, GF, GF, GC, GF, BF},
 {BF, GF, GC, GC, GC, GF, BF, BF, GF, GF, BF},
 {BF, GF, GC, GC, GF, BF, BF, BF, BF, BF, BF},
 {BF, GF, GC, GC, GF, BF, BF, BF, GF, GF, BF},
 {BF, GF, GC, GC, GC, GF, GF, GF, GC, GF, BF},
 {BF, BF, GF, GC, GC, GC, GC, GC, GC, GF, BF},
 {BF, BF, BF, GF, GC, GC, GC, GC, GF, BF, BF},
 {BF, BF, BF, BF, GF, GF, GF, GF, BF, BF, BF}
};

unsigned short SOLEIL[11][11] = 
{{BC, BC, BC, BC, BC, JF, BC, BC, BC, BC, BC},
 {BC, BC, BC, JF, BC, JF, BC, JF, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, JF, BC, BC, JF, JF, JF, BC, BC, JF, BC},
 {BC, BC, BC, JF, JF, JF, JF, JF, BC, BC, BC},
 {JF, JF, BC, JF, JF, JF, JF, JF, BC, JF, JF},
 {BC, BC, BC, JF, JF, JF, JF, JF, BC, BC, BC},
 {BC, JF, BC, BC, JF, JF, JF, BC, BC, JF, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, JF, BC, JF, BC, JF, BC, BC, BC},
 {BC, BC, BC, BC, BC, JF, BC, BC, BC, BC, BC}
};

unsigned short NUAGE[11][11] = 
{{BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, GF, BC, BC, BC, BC, BC, BC},
 {BC, BC, GF, GF, BB, GF, GF, GF, GF, BC, BC},
 {BC, GF, BB, BB, BB, BB, GF, BB, BB, GF, BC},
 {GF, BB, BB, BB, BB, BB, BB, BB, BB, BB, GF},
 {BC, GF, GF, GF, GF, GF, GF, GF, GF, GF, GF},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC}
};

unsigned short PLUIE[11][11] = 
{{GC, GC, GC, NN, GC, NN, NN, NN, GC, GC, GC},
 {GC, GC, NN, GF, NN, GF, GF, GF, NN, GC, GC},
 {GC, NN, GF, GF, GF, GF, GF, GF, GF, NN, GC},
 {NN, GF, GF, GF, GF, GF, GF, GF, GF, GF, NN},
 {GC, NN, NN, NN, NN, NN, NN, NN, NN, NN, GC},
 {GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, BC, GC, BC, GC, GC, GC, GC},
 {GC, GC, BC, GC, GC, BC, GC, BC, GC, GC, GC},
 {GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, BC, GC, BC, GC, BC, GC, GC, GC, GC, GC}
};

unsigned short NEIGE[11][11] =
{{GC, GC, GC, NN, GC, NN, NN, NN, GC, GC, GC},
 {GC, GC, NN, GF, NN, GF, GF, GF, NN, GC, GC},
 {GC, NN, GF, GF, GF, GF, GF, GF, GF, NN, GC},
 {NN, GF, GF, GF, GF, GF, GF, GF, GF, GF, NN},
 {GC, NN, NN, NN, NN, NN, NN, NN, NN, NN, GC},
 {GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, BB, GC, GC, GC, GC, BB, GC, GC},
 {GC, GC, BB, BB, BB, GC, GC, BB, BB, BB, GC},
 {GC, BB, GC, BB, GC, GC, BB, GC, BB, GC, GC},
 {BB, BB, BB, GC, GC, BB, BB, BB, GC, GC, GC},
 {GC, BB, GC, GC, GC, GC, BB, GC, GC, GC, GC}
};
