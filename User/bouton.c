#include "bouton.h"

void BP(void){
	
	bool bp = ((GPIO_ReadValue(2)>>10)&0x1);
	unsigned int i;
	if(bp != oldMaintienBouton){
		
		for(i = 0; i < 1000; ++i){}
		if(bp){
			
			lcd_clear(Blue);
			numMenu = (numMenu + 1)%3;
		}
	}
	
	oldMaintienBouton = bp;
}

void BP2(void){
	
	bool bp = ((GPIO_ReadValue(2)>>11)&0x1);
	unsigned int i;
	if(bp != oldMaintienBouton2){
		
		for(i = 0; i < 1000; ++i){}
		if(bp){
			
			sendMessage("*T20.0*");
		}
	}
	
	oldMaintienBouton2 = bp;
}
