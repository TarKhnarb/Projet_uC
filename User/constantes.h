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

//__________ bluetooth.h __________
#define PCONP_ *(unsigned long *)0x400FC0C4
	
//__________ buzzer.h____________
#define DO  	0
#define REb 	1
#define RE  	2
#define MIb 	3
#define MI 	 	4
#define FA  	5
#define SOLb 	6
#define SOL  	7
#define LAb  	8
#define LA  	9
#define SIb  	10
#define SI 		11

#define DEMI 5000
#define NOIR 10000
#define BLANCHE 20000
#define POINTE 30000

typedef int Note;
typedef int Octave;

#endif // CONTANT_H
