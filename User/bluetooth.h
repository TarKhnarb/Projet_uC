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
 * sendMessage(tab: char*, message à envoyer à l'application):
 * Envoie la chaîne de caractère souhaitée à l'application
 */
void sendMessage(char *msg);

/*
 * sendInteger(value: uint8_t (unsigned char), valeur (0/255) à envoyer à l'application):
 * Envoie l'entier à l'application
 */
void sendInterger(uint8_t value);

/*
 * UART0_IRQHandler():
 * Acquittement de UART0
 */
void UART0_IRQHandler(void);
