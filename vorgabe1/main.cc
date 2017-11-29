/* $Id$ */

#include "machine/cgascr.h"
#include "machine/keyctrl.h"
#include "machine/key.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "device/panic.h"
#include "device/keyboard.h"
#include "user/appl.h"
#include "guard/guard.h"
#include "thread/coroutine.h"
#include "user/loop.h"
#include "thread/scheduler.h"


CGA_Stream kout;
CPU cpu;
PIC pic;
Plugbox plugbox;
Panic panic;
Guard guard;
Scheduler schedule;

        
int main()
{
	Keyboard board;
	board.plugin();
	kout.clear();
	cpu.enable_int();
	kout.setpos(0, 0);
	Application app;
	Loop loop;
	schedule.ready(app);
	schedule.ready(loop);
	schedule.schedule();


	while(1);




	//	short a = -1;
	//	kout << "int a = " << dec << a << " ist hexadezimal: " << hex << a <<", binaer: "<<bin<<a<<endl<<" und octal: "<<oct<<a<<endl;
	//	short b = 20;
	//	kout<< "short b = " << dec << b << " ist hexadezimal: " << hex << b <<", binaer: "<<bin<<b<<endl<<" und octal: "<<oct<<b<<endl;
	//	long c = 2147483648;
	//	kout<< "long c = " << dec << c << " ist hexadezimal: " << hex << c <<", binaer: "<<bin<<c<<endl<<" und octal: "<<oct<<c<<endl;
	//	unsigned int d = 2147483648;
	//	kout<< "unsigned int d = " << dec << d << " ist hexadezimal: " << hex << d <<", binaer: "<<bin<<d<<endl<<" und octal: "<<oct<<d<<endl;
	//	scr.setpos(0, 0);
   return 0;
 }
