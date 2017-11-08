/* $Id$ */

/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "machine/cgascr.h"
#include "machine/keyctrl.h"
#include "machine/key.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "device/panic.h"
#include "device/keyboard.h"


CGA_Stream kout;
CPU cpu;
PIC pic;
Plugbox plugbox;
Panic panic;
CGA_Screen screen;
        
int main()
{
	Keyboard_Controller control;
	Key pressed;
	control.set_repeat_rate(31, 3);
	screen.clear();
//	char key[1];
	Keyboard board;

	board.plugin();

	screen.setpos(0, 0);
//	short a = -1;
//	kout << "int a = " << dec << a << " ist hexadezimal: " << hex << a <<", binaer: "<<bin<<a<<endl<<" und octal: "<<oct<<a<<endl;
//	short b = 20;
//	kout<< "short b = " << dec << b << " ist hexadezimal: " << hex << b <<", binaer: "<<bin<<b<<endl<<" und octal: "<<oct<<b<<endl;
//	long c = 2147483648;
//	kout<< "long c = " << dec << c << " ist hexadezimal: " << hex << c <<", binaer: "<<bin<<c<<endl<<" und octal: "<<oct<<c<<endl;
//	unsigned int d = 2147483648;
//	kout<< "unsigned int d = " << dec << d << " ist hexadezimal: " << hex << d <<", binaer: "<<bin<<d<<endl<<" und octal: "<<oct<<d<<endl;
//	scr.setpos(0, 0);
	while(1);//{
//		pressed = control.key_hit();
//
//		if(pressed.valid()){
//			key[0] = pressed.ascii();
//			screen.print(key, 1, 0x0f);
//		}
//	}
/* Hier muesst ihr selbst Code vervollstaendigen */         
         
/* Hier muesst ihr selbst Code vervollstaendigen */ 
                         
/* Hier muesst ihr selbst Code vervollstaendigen */                         
 
   return 0;
 }
