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
 * Appel les différentes fonctions avec des boutons
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

	// Autres fonctions utiles aux fonctions précédentes :

/*
 * char* concatene(char caractere, uint32_t value):
 * 		concatène une valeur avec le caractère souhaité afin d'envoyer la chaîne par bluetooth
 */
 
/*
 * void getWeatherIcon():
 *		Adapte l'icône à afficher sur l'écran LCD en fonction des valeurs recceuillies par les capteurs
 */
 
/*
 * void setDayNightIcon():
 * Adapte les icônes de jour/nuit sur l'écran LCD en fonction du capteur de luminosité
 */
