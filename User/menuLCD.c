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
		
		case 0:
			//Rectangle temps
			LCD_Draw_Rectangle(32,30,50,40,2,0,Black,Yellow);
			sprintf(chaine,"temps");
			LCD_Write_String (38,42,chaine,White,Blue);
		
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

