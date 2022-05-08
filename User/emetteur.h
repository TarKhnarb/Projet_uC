#include "lpc17xx_gpio.h"
#include "lpc17xx_timer.h"
#include "lpc17xx_pinsel.h"
#include "global.h"

/*
 * initTimer0():
 * Initialise le timer 0 avec les params suivants :
 *		- Match avec MR0
 *		- Interruption lors du match
 *		- Reset lors du match
 *		- Arrêt lors du match
 *		- Précision us
 *		- Durée : 12us
 */
void initTimer0(void);

/*
 * startTimer0():
 * Démarre le timer 0
 */
void startTimer0(void);

/*
 * stopTimer0():
 * Arrête le timer 0
 */
void stopTimer0(void);

/*
 * initTimer1():
 * Initialise le timer 1 avec les params suivants :
 *		- Match avec MR1
 *		- Interruption lors du match
 *		- Reset lors du match
 *		- Arrêt lors du match
 *		- Précision us
 *		- Durée : 100us par défaut
 */
void initTimer1(void);

/*
 * startTimer1(duree: uint32_t, durée en us de l'interruptionavec @flagTIM1):
 * Démarre le timer 1
 */
void startTimer1(uint32_t duree);

/*
 * TIMER1_IRQHandler():
 * Interruption du timer 1
 */
void TIMER1_IRQHandler(void);

/*
 * sendMessage(tab: char*, message de 1 octet à envoyer à l'application):
 * Envoie la chaîne de caractère souhaitée à l'application
 */
void sendMessage(char *msg);

