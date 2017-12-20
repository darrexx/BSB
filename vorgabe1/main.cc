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
#include "syscall/guarded_organizer.h"
#include "device/watch.h"
#include "guard/secure.h"
#include "syscall/guarded_semaphore.h"


CGA_Stream kout;
CPU cpu;
PIC pic;
Plugbox plugbox;
Panic panic;
Guard guard;
Guarded_Organizer schedule;
Application app;
Loop loop;

        
int main()
{
	Secure secure;
	Keyboard board;
	board.plugin();
	Watch watch(20000);
	watch.windup();
	kout.clear();
	cpu.enable_int();
	kout.setpos(0, 0);
	schedule.Scheduler::ready(app);
	schedule.Scheduler::ready(loop);
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
