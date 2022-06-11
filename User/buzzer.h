#ifndef BUZZER_H
#define BUZZER_H

#include <math.h>
#include "lpc17xx_pinsel.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_timer.h"
#include "constantes.h"
#include "global.h"

void initBuzzer(void);

int jouerNote(Note n, Octave o);

void initialise_melodie1(void);

void initTimer0(void);

void startTimer0(void);

void jouerBuzzer(void);

void jouerMelodie(void);

#endif
