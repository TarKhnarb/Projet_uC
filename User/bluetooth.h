#include "lpc17xx_gpio.h"
#include "lpc17xx_timer.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_uart.h"
#include "touch\ili_lcd_general.h"
#include "menuLCD.h"
#include "global.h"
#include "constantes.h"

#include <stdio.h>
#include <string.h>

/*
 * initBluetooth()
 * Initialise le bluetooth sur la carte (cf shema 1 Annexe case A3)
 */
void initBluetooth(void);

/*
 * sendMessage(tab: char*, message � envoyer � l'application):
 * Envoie la cha�ne de caract�re souhait�e � l'application
 */
void sendMessage(char *msg);

/*
 * sendInteger(value: uint8_t (unsigned char), valeur (0/255) � envoyer � l'application):
 * Envoie l'entier � l'application
 */
void sendInterger(uint8_t value);

/*
 * UART0_IRQHandler():
 * Acquittement de UART0
 */
void UART0_IRQHandler(void);

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
