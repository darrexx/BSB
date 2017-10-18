/* $Id$ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "machine/cgascr.h"
        
int main()
{
	CGA_Screen scr;
	scr.show(1, 1, 'A', 0x0f);
	scr.setpos(0, 1);

	int x;
	int y;
	scr.getpos(x, y);
	if (x == 0 && y == 1){
		scr.show(1, 1, 'B', 0x0A);
	}
	scr.setpos(0, 10);
	scr.print("Test", 4, 0x0f);
/* Hier muesst ihr selbst Code vervollstaendigen */         
         
/* Hier muesst ihr selbst Code vervollstaendigen */ 
                         
/* Hier muesst ihr selbst Code vervollstaendigen */                         
 
   return 0;
 }
