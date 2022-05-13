#include "menuLCD.h"
/************
 * initMenu *
 ************/
void initMenu(void){
	
	LCD_Initialization();
	numMenu = 0;
}

void menu(void){
	switch(numMenu){
		
		// x: 0->239
		// y: 0->319
		case 0:
			//Rectangle temps
			LCD_Draw_Rectangle(32,30,50,40,2,0,Black,Yellow);
			//sprintf(chaine,"temps");
			//LCD_Write_String (38,42,chaine,White,Blue);
			printPixelArt(sensorToUpdate, 38, 42);
		
			//Rectangle jour/nuit
			LCD_Draw_Rectangle(88,30,50,40,2,0,Black,Yellow);
			sprintf(chaine,"J/N");
			LCD_Write_String (102,42,chaine,White,Blue);
		
			//Rectangle température
			LCD_Draw_Rectangle(168,30,50,40,2,0,Black,Yellow);
			sprintf(chaine, "%.1d*c", temperature); // sprintf(chaine,"C*");
			LCD_Write_String (186,42,chaine,White,Blue);
			
			//Rectangle heure
			LCD_Draw_Rectangle(32,150,186,40,2,0,Black,Yellow);
			sprintf(chaine,"HH:MM:SS");
			LCD_Write_String (95,162,chaine,White,Blue);
			break;
			//
		
		case 1:
			//Rectangle temps
			LCD_Draw_Rectangle(88,30,70,40,2,0,Black,Yellow);
			sprintf(chaine,"temps");
			LCD_Write_String (102,42,chaine,White,Blue);
		
			//Rectangle température
			LCD_Draw_Rectangle(32,110,186,40,2,0,Black,Yellow);
			sprintf(chaine, "%.1d", temperature);
			LCD_Write_String (80,122,chaine,White,Blue);
		
			//Rectangle humidité
			LCD_Draw_Rectangle(32,170,186,40,2,0,Black,Yellow);
			sprintf(chaine, "%.1d", humidite);
			LCD_Write_String (80,182,chaine,White,Blue);
			
			break;
		
		case 2:
			//Rectangle lumière
			LCD_Draw_Rectangle(32,30,186,40,2,0,Black,Yellow);
			sprintf(chaine, "%d", luminosite);
			LCD_Write_String (100,42,chaine,White,Blue);
			
			//Rectangle C02
			LCD_Draw_Rectangle(32,130,186,40,2,0,Black,Yellow);
			sprintf(chaine, "%d", co2);
			LCD_Write_String (95,142,chaine,White,Blue);
			break;
		
		default:
			break;
	}
}

void subPrintPixelArt(unsigned short pxl[21][21], unsigned int x, unsigned int y, unsigned int e){

	int i,j,k,h;
	
	for(j = y; j < y+21; ++j){
		
		lcd_SetCursor(x,j);
		rw_data_prepare();

		for(i = x; i <= x+21; ++i){
			
			write_data(pxl[j-y][i-x]);
		}
	}
	/*	Todo faire en sorte que le write data fonctionne
	for(j = y; j < y+(21*e); j+=e){
		
		lcd_SetCursor(x,j);
		rw_data_prepare();

		for(i = x; i <= x+(21*e); i+=e){
			
			for(h = j; h <= j+e; ++h){
				for(k = i; k <= i+e; ++k){
					
					write_data(pxl[((j-y)%21)][k-(x+21*e)]);
				}
			}
		}
	}*/
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
