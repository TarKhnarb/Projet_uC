// mettez dans ce fichier toutes les constantes et définitions 
// des nouveaux types que vous souhaitez
#ifndef CONTANT_H
#define CONTANT_H

typedef enum{
	jaune,
	vert,
	rouge,
	bleu
} touche ;

typedef enum{
	
	Temperature,
	Luminosite,
	CO2,
	Humidite,
	Max
} Sensors;


//__________ CAN.h __________
#define PCONP_ *(unsigned long *)0x400FC0C4

#endif // CONTANT_H
