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
 *		- Arr�t lors du match
 *		- Pr�cision us
 *		- Dur�e : 12us
 */
void initTimer0(void);

/*
 * startTimer0():
 * D�marre le timer 0
 */
void startTimer0(void);

/*
 * stopTimer0():
 * Arr�te le timer 0
 */
void stopTimer0(void);

/*
 * initTimer1():
 * Initialise le timer 1 avec les params suivants :
 *		- Match avec MR1
 *		- Interruption lors du match
 *		- Reset lors du match
 *		- Arr�t lors du match
 *		- Pr�cision us
 *		- Dur�e : 100us par d�faut
 */
void initTimer1(void);

/*
 * startTimer1(duree: uint32_t, dur�e en us de l'interruptionavec @flagTIM1):
 * D�marre le timer 1
 */
void startTimer1(uint32_t duree);

/*
 * TIMER1_IRQHandler():
 * Interruption du timer 1
 */
void TIMER1_IRQHandler(void);

/*
 * sendMessage(tab: char*, message de 1 octet � envoyer � l'application):
 * Envoie la cha�ne de caract�re souhait�e � l'application
 */
void sendMessage(char *msg);

