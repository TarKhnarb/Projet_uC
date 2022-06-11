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
 * 	Initialise le capteur de température
 */
void initTempSensor(void);

/*
 * getTempSensor()
 * 	Récupère la valeur du capteur de température
 */
void getTempSensor(void);

/*
 * initLightSensor()
 * 	Initialise le capteur de luminosité
 */
void initLightSensor(void);

/*
 * getLightSensor()
 * 	Récupère la valeur du capteur de luminosité
 */
void getLightSensor(void);

/*
 * initRainSensor()
 * 	Initialise le capteur de pluie
 */
void initRainSensor(void);

/*
 * getRainSensor()
 * 	Récupère la valeur du capteur de pluie
 */
void getRainSensor(void);
