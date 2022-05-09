#include "lpc17xx_gpio.h"
#include "lpc17xx_timer.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_uart.h"
#include "touch\ili_lcd_general.h"
#include "menuLCD.h"
#include "global.h"

#include <stdio.h>
#include <string.h>

void initBluetooth(void);

/*
 * sendMessage(tab: char*, message de 1 octet � envoyer � l'application):
 * Envoie la cha�ne de caract�re souhait�e � l'application
 */
void sendMessage(char *msg);

void sendInterger(int value);

void UART0_IRQHandler(void);
