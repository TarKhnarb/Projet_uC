#include "affichagelcd.h"

void LCD_Draw_Line(unsigned int x, unsigned int y, unsigned int l,unsigned int e, char orientation, unsigned short color)
{
	int i,j;
	if(orientation=='v')
	{
		for(j=y;j<=y+l;j++)
		{
			lcd_SetCursor(x,j);//on place le curseur � la bonne position
			rw_data_prepare();
			for(i=0;i<=e;i++)
			{
				write_data(color);//on trace un point et on passe � la position suivante
			}
		}
	}
	else//orientation='h'
	{
		for(j=y;j<=y+e;j++)
		{
			lcd_SetCursor(x,j);//on place le curseur � la bonne position
			rw_data_prepare();
			for(i=0;i<=l;i++)
			{
				write_data(color);//on trace un point et on passe � la position suivante
			}
		}
	}
}

void LCD_Draw_Rectangle(unsigned int x, unsigned int y, unsigned int lng, unsigned int lrg, unsigned int e, unsigned short plein, unsigned short e_color, unsigned short bg_color)
{
	//dessiner fond
	if(plein==1)
	{
		LCD_Draw_Line(x,y,lng,lrg,'h',bg_color);
	}
	
	//dessiner bordures
	LCD_Draw_Line(x,y,lng,e,'h',e_color);
	LCD_Draw_Line(x+lng-e,y,lrg,e,'v',e_color);
	LCD_Draw_Line(x,y+lrg-e,lng,e,'h',e_color);
	LCD_Draw_Line(x,y,lrg,e,'v',e_color);
}

