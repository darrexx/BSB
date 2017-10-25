/* $Id$ */

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                             C G A _ S C R E E N                           */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse kann man auf den Bildschirm des PCs zugreifen.    */
/* Der Zugriff erfolgt direkt auf der Hardwareebene, d.h. ueber den Bild-    */
/* schirmspeicher bzw. die I/O-Ports der Grafikkarte.                        */
/*****************************************************************************/

#include "machine/cgascr.h"

/* Hier muesst ihr selbst Code vervollstaendigen */ 

void CGA_Screen::show(int x, int y, char c, unsigned char attrib)
{
	char *pos;

	pos= CGA_START + 2*(x+y*80);
	*pos = c;
	*(pos+1) = attrib;
}
void CGA_Screen::setpos(int x, int y)
{
	int pos = x+y*80;


	index.outb(15);
	daten.outb(pos & 0xFF);

	index.outb(14);
	daten.outb((pos>>8)&0xFF);

}

void CGA_Screen::getpos(int &x, int &y)
{
	index.outb(14);
	int high = daten.inb();

	index.outb(15);
	int low = daten.inb();

	int pos = (high<<8)+low;

	y = pos/80;
	x = pos%80;
}

void CGA_Screen::print(char* text, int length, unsigned char attrib)
{
	int x;
	int y;
	for(int i = 0; i<length;i++){
		CGA_Screen::getpos(x,y);
		if(text[i]=='\n'){
			CGA_Screen::setpos(0, y+1);
			continue;
		}
		CGA_Screen::show(x, y, text[i], attrib);
		if(x<79){
			CGA_Screen::setpos(x+1, y);
		}else{
			CGA_Screen::setpos(0, y+1);
		}
	}
}
