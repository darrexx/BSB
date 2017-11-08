#ifndef __screen_include__
#define __screen_include__

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

#include "machine/io_port.h"

class CGA_Screen
 {
private:
/* Hier muesst ihr selbst Code vervollstaendigen */ 
	char * const CGA_START;
	IO_Port index;
	IO_Port daten;
	void scroll();
	void clearLine(int pos);

   CGA_Screen(const CGA_Screen &copy); // Verhindere Kopieren
public:
   CGA_Screen()
	:CGA_START((char*)0xb8000),
	 index(0x3d4),
	 daten(0x3d5)
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 {}

   void show(int x, int y, char c, unsigned char attrib);
   void setpos(int x, int y);
   void getpos(int &x, int &y);
   void print(char* text, int length, unsigned char attrib);
   void clear();

/* Hier muesst ihr selbst Code vervollstaendigen */ 
 };

/* Hier muesst ihr selbst Code vervollstaendigen */ 

#endif

