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
			if(y<24){
				CGA_Screen::setpos(0, y+1);
			} else{
				CGA_Screen::scroll();
				CGA_Screen::setpos(0, y);
			}
			continue;
		}
		CGA_Screen::show(x, y, text[i], attrib);
		if(x<79){
			CGA_Screen::setpos(x+1, y);
		}else{
			if(y<24){
			CGA_Screen::setpos(0, y+1);
			} else{
				CGA_Screen::scroll();
				CGA_Screen::setpos(0, y);
			}
		}
	}
}

void CGA_Screen::scroll()
{

	for(int i=0;i<80;i++){
		for(int j=1;j<25;j++){
			char *pos_from;
			char *pos_to;

			pos_from= CGA_START + 2*(i+j*80);
			pos_to= CGA_START + 2*(i+(j-1)*80);


			*pos_to = *pos_from;
			*(pos_to+1) = *(pos_from+1);
		}
	}

	clearLine(24);
}


void CGA_Screen::clearLine(int pos)
{
	int j=pos;

	if(pos<0||pos>24){return;}
	for(int i=0;i<80;i++){

		char *pos;

		pos= CGA_START + 2*(i+j*80);
		*pos = ' ';
		*(pos+1) = 0x0F;
	}
}

void CGA_Screen::clear(){
	for(int i=0;i<=24;i++){
		clearLine(i);
	}
}

void CGA_Screen::bluescreen(char* text){
	for(int i=0;i<=24;i++){
		int j=i;

		if(i<0||i>24){return;}
		for(int k=0;k<80;k++){

			char *pos;

			pos= CGA_START + 2*(k+j*80);
			*pos = ' ';
			*(pos+1) = 0x1F;
		}
	}

	bool terminated=false;
		int counter=0;
		while(!terminated){
			if(text[counter]!='\0'){
				counter++;
			}else{
				terminated=true;
			}
		}
	setpos(0,0);
	print(text,counter,0x1F);
}
