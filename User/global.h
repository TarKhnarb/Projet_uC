//===========================================================//
// Projet Micro - SNUM1 - ENSSAT														 //
//===========================================================//

#include "constantes.h" // fichier contenant toutes les constantes du projet
#include <stdint.h>

#define PCONP_ *(unsigned long *)0x400FC0C4

// mettez ici toutes les "extern" correspondant aux déclarations contenues dans globadec.h

extern char chaine[30]; // buffer pour l'affichage sur le LCD
extern uint16_t touch_x, touch_y ;

//__________ menu.h __________
extern unsigned char numMenu;
extern unsigned char maintienBouton;
extern unsigned char oldMaintienBouton;

//__________ CAN.h __________
extern uint16_t temperature;
