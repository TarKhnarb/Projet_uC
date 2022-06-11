#include "bluetooth.h"
#include "global.h"
#include "menuLCD.h"
#include "capteurs.h"
#include "buzzer.h"

#include <stdlib.h>
#include <stdio.h>

/*
 * initialisations():
 * Initalise :
 *			- Capteurs
 *			- Bluetooth
 *			- Ecran LCD
 */
void initialisations(void);

/*
 * boutons():
 * Appel les différentes fonctions des boutons
 */
void boutons(void);

/*
 * bluetooth():
 * Gère la récupérations de valeurs et l'envoie vers l'application
 */
void bluetooth(void);

/*
 * stationMeteo():
 * Fonction principale de notre application
 */
void stationMeteo(void);
