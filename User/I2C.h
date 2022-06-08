#include "lpc17xx_libcfg_default.h"
#include "lpc17xx_i2c.h"
#include "lpc17xx.h"

void initI2C0(void);

void ecrire(uint32_t adresse, uint8_t *data, uint32_t length);

void lire(uint32_t adresse, uint8_t *data, uint32_t length, uint8_t *receivedData, uint32_t receivedLength);
