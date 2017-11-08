/* $Id$ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "machine/cgascr.h"
#include "machine/keyctrl.h"
#include "machine/key.h"
#include "device/cgastr.h"
        
int main()
{
	CGA_Screen scr;
	Keyboard_Controller control;
	Key pressed;
	control.set_repeat_rate(0x00, 3);
	scr.clear();
	char key[1];
	scr.show(1, 1, 'A', 0x0f);
	scr.setpos(0, 1);

	int x;
	int y;
	scr.getpos(x, y);
	if (x == 0 && y == 1){
		scr.show(1, 1, 'B', 0x0A);
	}

//	scr.setpos(0, 0);
//	scr.print("debug", 5, 0x0f);

	scr.setpos(0, 10);
	kout<<"a"<<endl<<"b"<<endl<<"test"<<endl;
	short a = -1;
	kout << "a = " << dec << a << " ist hexadezimal: " << hex << a <<", binaer: "<<bin<<a<<" und octal: "<<oct<<a<<endl;
//	scr.setpos(0, 0);
	while(1){
		pressed = control.key_hit();

		if(pressed.valid()){
			key[0] = pressed.ascii();
			scr.print(key, 1, 0x0f);
		}
	}
/* Hier muesst ihr selbst Code vervollstaendigen */         
         
/* Hier muesst ihr selbst Code vervollstaendigen */ 
                         
/* Hier muesst ihr selbst Code vervollstaendigen */                         
 
   return 0;
 }
