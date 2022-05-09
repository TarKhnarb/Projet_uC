#include "bouton.h"
#include "capteurs.h"
#include "constantes.h"
#include "bluetooth.h"
#include "menuLCD.h"

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
