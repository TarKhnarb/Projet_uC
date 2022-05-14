#include "menuLCD.h"
/************
 * initMenu *
 ************/
void initMenu(void){
	
	LCD_Initialization();
	
	numMenu = 0;	// [3]
	temps = 0;		// [5]
	jourNuit = 1;	// [2]
}

void menu(void){
	switch(numMenu){
		
		// x: 0->239
		// y: 0->319
		case 0:
			//Rectangle temps
			LCD_Draw_Rectangle(28, 28, 47, 47, 2, 0, Black,Yellow);
			printPixelArt(temps, 30, 30);
		
			//Rectangle jour/nuit
			LCD_Draw_Rectangle(96, 28, 47, 47, 2, 0, Black,Yellow);
			printPixelArt(jourNuit, 98, 30);
		
			//Rectangle température
			LCD_Draw_Rectangle(165, 28, 47, 47, 2, 0, Black,Yellow);
			sprintf(chaine, "%.1d *c", temperature);
			LCD_Write_String (175, 45, chaine, White, Blue);
			
			//Rectangle heure
			LCD_Draw_Rectangle(69, 138, 100, 47, 2, 0, Black, Yellow);
			sprintf(chaine,"HH:MM:SS");
			LCD_Write_String (88, 155, chaine, White, Blue);
			break;
			//
		
		case 1:
			//Rectangle jour/nuit
			LCD_Draw_Rectangle(96, 28, 47, 47, 2, 0, Black,Yellow);
			printPixelArt(jourNuit, 98, 30);
		
			//Rectangle température
			LCD_Draw_Rectangle(32, 110, 186, 47, 2, 0, Black,Yellow);
			sprintf(chaine, "Temperature: %.1d *c", temperature);
			LCD_Write_String (50, 125, chaine, White, Blue);
		
			//Rectangle humidité
			LCD_Draw_Rectangle(32, 177, 186, 47, 2, 0, Black,Yellow);
			sprintf(chaine, "Humidite: %d %%", humidite);
			LCD_Write_String (50, 192, chaine, White, Blue);
			
			break;
		
		case 2:
			//Rectangle temps
			LCD_Draw_Rectangle(96, 28, 47, 47, 2, 0, Black,Yellow);
			printPixelArt(temps, 98, 30);
		
			//Rectangle luminosité
			LCD_Draw_Rectangle(32, 110, 186, 47, 2, 0, Black,Yellow);
			sprintf(chaine, "Luminosite: %d %%", luminosite);
			LCD_Write_String (50, 128, chaine, White, Blue);
		
			//Rectangle CO2
			LCD_Draw_Rectangle(32, 177, 186, 47, 2, 0, Black,Yellow);
			sprintf(chaine, "CO2: %d %%", co2);
			LCD_Write_String (50, 195, chaine, White, Blue);
			break;
		
		default:
			break;
	}
}

void subPrintPixelArt(unsigned short pxl[21][21], unsigned int x, unsigned int y, unsigned int e){

	int i,j,k,h;
	
	for(j = 0; j < 21; ++j){
		for(i = 0; i < 21; ++i){
		
			for(h = 1; h <= e; ++h){
				for(k = 1; k <= e; ++k){
					
					lcd_SetCursor(x+i*e+k, y+j*e+h);
					rw_data_prepare();
					write_data(pxl[j][i]);
				}			
			}	
		}
	}
}

void printPixelArt(uint8_t temps, unsigned int x, unsigned int y){
	
	if(temps == 0){
		
		subPrintPixelArt(LUNE, x, y, 2);
	}
	else if (temps == 1){
		
		subPrintPixelArt(SOLEIL, x, y, 2);
	}
	else if (temps == 2){
		
		subPrintPixelArt(NUAGE, x, y, 2);
	}
	else if (temps == 3){
		
		subPrintPixelArt(PLUIE, x, y, 2);
	}
	else if (temps == 4){
		
		subPrintPixelArt(NEIGE, x, y, 2);
	}
}
