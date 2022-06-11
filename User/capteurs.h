#include <math.h>
#include <stdlib.h>
#include "lpc17xx_adc.h"
#include "LPC17xx.h"
#include "global.h"
#include "lpc17xx_pinsel.h"
#include "touch\ili_lcd_general.h"


/*
 * initSensors():
 * 	Initialise tous les capteurs
 */
void initSensors(void);

/*
 * initTempSensor()
 * 	Initialise le capteur de temp�rature
 */
void initTempSensor(void);

/*
 * getTempSensor()
 * 	R�cup�re la valeur du capteur de temp�rature
 */
void getTempSensor(void);

/*
 * initLightSensor()
 * 	Initialise le capteur de luminosit�
 */
void initLightSensor(void);

/*
 * getLightSensor()
 * 	R�cup�re la valeur du capteur de luminosit�
 */
void getLightSensor(void);

/*
 * initRainSensor()
 * 	Initialise le capteur de pluie
 */
void initRainSensor(void);

/*
 * getRainSensor()
 * 	R�cup�re la valeur du capteur de pluie
 */
void getRainSensor(void);
