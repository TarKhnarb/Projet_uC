//===========================================================//
// Projet Micro - SNUM1 - ENSSAT														 //
//===========================================================//
#include <stdint.h>
#include <stdbool.h>

#include "constantes.h"

<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
// mettez ici toutes les "extern" correspondant aux déclarations contenues dans globadec.h

extern char chaine[30]; // buffer pour l'affichage sur le LCD
extern uint16_t touch_x, touch_y ;
extern unsigned char numMenu;
<<<<<<< Updated upstream
extern unsigned char maintienBouton;
extern unsigned char oldMaintienBouton;
=======

//__________ bouton.h __________
extern bool maintienBouton;
extern bool maintienBouton2;

extern bool oldMaintienBouton;
extern bool oldMaintienBouton2;

//__________ CAN.h __________
extern uint16_t temperature;


//__________ emetteur.h __________
extern bool flagTIM1;
>>>>>>> Stashed changes
