#include <math.h>
#include <stdlib.h>
#include "lpc17xx_adc.h"
#include "LPC17xx.h"
#include "global.h"
#include "lpc17xx_pinsel.h"
#include "touch\ili_lcd_general.h"

void initSensors(void);

/*
 * recupTemp()
 * 
 */
void initTempSensor(void);

void getTempSensor(void);

void initLightSensor(void);

void getLightSensor(void);

void initMoistureSensor(void);

void getMoistureSensor(void);

void initRainSensor(void);

void getRainSensor(void);
