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

//__________ menuLCD.h __________
const unsigned short BF = 0x1336;	// pixel Bleu Foncé
const unsigned short BC = 0x38DA;	// pixel Bleu Clair
const unsigned short GF = 0xAAEA; // pixel Gris Foncé
const unsigned short GC = 0xDD9D; // pixel Gris Clair
const unsigned short NN = 0x0000;	// pixel Noir Noir
const unsigned short BB = 0xFFFF; // pixel Blanc Blanc
const unsigned short JF = 0xFE23; // pixel Jaune Foncé

unsigned short LUNE[21][21] = 
{{BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF},
 {BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF},
 {BF, BF, BF, BF, BF, BF, BF, BF, NN, NN, NN, NN, NN, NN, BF, BF, BF, BF, BF, BF, BF},
 {BF, BF, BF, BF, BF, BF, NN, NN, GF, GF, GF, GF, GF, GF, NN, NN, BF, BF, BF, BF, BF},
 {BF, BF, BF, BF, BF, NN, GF, GF, GF, GC, GC, GC, GC, GC, GF, GF, NN, BF, BF, BF, BF},
 {BF, BF, BF, BF, NN, GF, GF, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, NN, BF, BF, BF},
 {BF, BF, BF, NN, GF, GF, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, NN, BF, BF, BF},
 {BF, BF, BF, NN, GF, GC, GC, GC, GC, GC, GC, NN, NN, NN, NN, GC, GC, GC, NN, BF, BF},
 {BF, BF, NN, GF, GC, GC, GC, GC, GC, GC, NN, BF, BF, BF, BF, NN, NN, GC, NN, BF, BF},
 {BF, BF, NN, GF, GC, GC, GC, GC, GF, NN, BF, BF, BF, BF, BF, BF, NN, NN, NN, BF, BF},
 {BF, BF, NN, GF, GC, GC, GC, GC, GF, NN, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF},
 {BF, BF, NN, GF, GC, GC, GC, GC, GF, NN, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF},
 {BF, BF, NN, GF, GC, GC, GC, GC, GF, NN, BF, BF, BF, BF, BF, BF, NN, NN, NN, BF, BF},
 {BF, BF, NN, GF, GC, GC, GC, GC, GF, GF, NN, BF, BF, BF, BF, NN, NN, GF, NN, BF, BF},
 {BF, BF, BF, NN, GF, GC, GC, GC, GC, GF, GF, NN, NN, NN, NN, GF, GC, GF, NN, BF, BF},
 {BF, BF, BF, NN, GF, GC, GC, GC, GC, GC, GF, GF, GF, GF, GF, GC, GF, NN, BF, BF, BF},
 {BF, BF, BF, BF, NN, GF, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GF, NN, BF, BF, BF},
 {BF, BF, BF, BF, BF, NN, GF, GF, GC, GC, GC, GC, GC, GF, GF, GF, NN, BF, BF, BF, BF},
 {BF, BF, BF, BF, BF, BF, NN, NN, GF, GF, GF, GF, GF, GF, NN, NN, BF, BF, BF, BF, BF},
 {BF, BF, BF, BF, BF, BF, BF, BF, NN, NN, NN, NN, NN, NN, BF, BF, BF, BF, BF, BF, BF},
 {BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF, BF}
};

unsigned short SOLEIL[21][21] = 
{{BC, BC, BC, BC, BC, BC, BC, BC, BC, JF, BC, JF, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, JF, JF, JF, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, JF, BC, BC, JF, JF, JF, BC, BC, JF, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, JF, JF, JF, BC, BC, JF, BC, BC, JF, JF, JF, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, JF, JF, BC, BC, BC, BC, BC, JF, JF, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, JF, BC, BC, BC, BC, BC, JF, JF, JF, BC, BC, BC, BC, BC, JF, BC, BC, BC},
 {BC, BC, JF, JF, JF, BC, BC, JF, JF, JF, JF, JF, JF, JF, BC, BC, JF, JF, JF, BC, BC},
 {BC, BC, BC, JF, JF, BC, JF, JF, JF, JF, JF, JF, JF, JF, JF, BC, JF, JF, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, JF, JF, JF, JF, JF, JF, JF, JF, JF, BC, BC, BC, BC, BC, BC},
 {JF, JF, JF, BC, BC, JF, JF, JF, JF, JF, JF, JF, JF, JF, JF, JF, BC, BC, JF, JF, JF},
 {BC, JF, JF, JF, BC, JF, JF, JF, JF, JF, JF, JF, JF, JF, JF, JF, BC, JF, JF, JF, BC},
 {JF, JF, JF, BC, BC, JF, JF, JF, JF, JF, JF, JF, JF, JF, JF, JF, BC, BC, JF, JF, JF},
 {BC, BC, BC, BC, BC, BC, JF, JF, JF, JF, JF, JF, JF, JF, JF, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, JF, JF, BC, JF, JF, JF, JF, JF, JF, JF, JF, JF, BC, JF, JF, BC, BC, BC},
 {BC, BC, JF, JF, JF, BC, BC, JF, JF, JF, BC, JF, JF, JF, BC, BC, JF, JF, JF, BC, BC},
 {BC, BC, BC, JF, BC, BC, BC, BC, BC, JF, JF, JF, BC, BC, BC, BC, BC, JF, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, JF, JF, BC, BC, BC, BC, BC, JF, JF, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, JF, JF, JF, BC, BC, JF, BC, BC, JF, JF, JF, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, JF, BC, BC, JF, JF, JF, BC, BC, JF, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, JF, JF, JF, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, JF, BC, JF, BC, BC, BC, BC, BC, BC, BC, BC, BC}
};

unsigned short NUAGE[21][21] = 
{{BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, GC, GC, GC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, GC, GC, BB, BB, BB, GC, GC, BC, GC, GC, GC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, GC, BB, BB, BB, BB, BB, BB, BB, GC, BB, BB, BB, GC, BC, BC, BC, BC, BC},
 {BC, BC, BC, GC, BB, BB, BB, BB, BB, BB, BB, GC, BB, BB, BB, BB, GC, BC, BC, BC, BC},
 {BC, GC, GC, BB, BB, BB, BB, GC, GC, GC, BB, BB, BB, BB, BB, BB, BB, GC, GC, BC, BC},
 {GC, BB, BB, BB, BB, GC, GC, BB, BB, BB, GC, GC, BB, GC, GC, GC, BB, BB, GC, BC, BC},
 {GC, BB, BB, BB, GC, BB, BB, BB, BB, BB, BB, BB, GC, BB, BB, BB, GC, BB, GC, BC, BC},
 {BC, GC, GC, GC, GC, BB, BB, BB, BB, BB, BB, BB, GC, BB, BB, BB, BB, GC, BC, BC, BC},
 {BC, GC, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, GC, GC, BC},
 {GC, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, GC},
 {GC, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, GC},
 {BC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
};

unsigned short PLUIE[21][21] = 
{{GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, BB, BB, BB, BB, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC, GC, BB, BB, BB, GC, BB, GC, GC, GC, GC, BB, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC, BB, GC, GC, GC, BB, GC, GC, GC, GC, GC, GC, BB, GC, GC, GC, GC},
 {GC, GC, GC, GC, BB, GC, GC, GC, BB, GC, GC, GC, GC, GC, GC, GC, GC, BB, BB, GC, GC},
 {GC, GC, BB, BB, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, BB, GC},
 {GC, BB, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, BB},
 {GC, BB, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, BB},
 {GC, BB, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, BB},
 {GC, GC, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, GC},
 {GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC, GC, BC, GC, GC, BC, GC, GC, BC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC, GC, BC, GC, GC, BC, GC, GC, BC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC, BC, GC, GC, BC, GC, GC, BC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC, BC, GC, GC, BC, GC, GC, BC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, BC, GC, GC, BC, GC, GC, BC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, BC, GC, GC, BC, GC, GC, BC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC},
 {GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC}
};

unsigned short NEIGE[21][21] =
{{BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, GC, GC, GC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, GC, GC, BB, BB, BB, GC, GC, BC, GC, GC, GC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, GC, BB, BB, BB, BB, BB, BB, BB, GC, BB, BB, BB, GC, BC, BC, BC, BC},
 {BC, BC, BC, BC, GC, BB, BB, BB, BB, BB, BB, BB, GC, BB, BB, BB, BB, GC, BC, BC, BC},
 {BC, BC, GC, GC, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, GC, GC, BC},
 {BC, GC, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, GC},
 {BC, GC, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, BB, GC},
 {BC, BC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, GC, BC},
 {BC, BC, BC, BC, BC, BC, BB, BC, BC, BC, BC, BB, BC, BC, BC, BC, BB, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BB, BB, BB, BC, BC, BB, BB, BB, BC, BC, BB, BB, BB, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BB, BC, BC, BC, BC, BB, BC, BC, BC, BC, BB, BC, BC, BC, BC},
 {BC, BC, BC, BB, BC, BC, BC, BC, BB, BC, BC, BC, BC, BB, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BB, BB, BB, BC, BC, BB, BB, BB, BC, BC, BB, BB, BB, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BB, BC, BC, BC, BC, BB, BC, BC, BC, BC, BB, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BB, BC, BC, BC, BC, BB, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BB, BB, BB, BC, BC, BB, BB, BB, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BB, BC, BC, BC, BC, BB, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC},
 {BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC, BC}
};
