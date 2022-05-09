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
 * sendMessage(tab: char*, message de 1 octet à envoyer à l'application):
 * Envoie la chaîne de caractère souhaitée à l'application
 */
void sendMessage(char *msg);

void sendInterger(int value);

void UART0_IRQHandler(void);
