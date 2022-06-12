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
 * initTimer1():
 * Initalise le timer 1 pour la gestion des prises de donn�es et envoie pour l'application
 */
void initTimer1(void);

/*
 * startTimer1(duree: uint32_t, dur�e en ms)
 * Lance timer 1 pour duree us
 */
void startTimer1(uint32_t duree);

/*
 * TIMER1_IRQHandler
 */
void TIMER1_IRQHandler(void);

/*
 * boutons():
 * Appel les diff�rentes fonctions avec des boutons
 */
void boutons(void);

/*
 * bluetooth():
 * G�re la r�cup�rations de valeurs et l'envoie vers l'application
 */
void bluetooth(void);

/*
 * stationMeteo():
 * Fonction principale de notre application
 */
void stationMeteo(void);

	// Autres fonctions utiles aux fonctions pr�c�dentes :

/*
 * char* concatene(char caractere, uint32_t value):
 * 		concat�ne une valeur avec le caract�re souhait� afin d'envoyer la cha�ne par bluetooth
 */
 
/*
 * void getWeatherIcon():
 *		Adapte l'ic�ne � afficher sur l'�cran LCD en fonction des valeurs recceuillies par les capteurs
 */
 
/*
 * void setDayNightIcon():
 * Adapte les ic�nes de jour/nuit sur l'�cran LCD en fonction du capteur de luminosit�
 */
