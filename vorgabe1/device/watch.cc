/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/


#include "device/watch.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "syscall/guarded_scheduler.h"

void Watch::windup (){
    plugbox.assign(Plugbox::TIMER, *this);
    pic.allow(PIC::timer);
}

bool Watch::prologue (){
	return true;
}
//TODO test mit ausgabe statt schedule
void Watch::epilogue (){
	schedule.Scheduler::resume();
//	kout.setpos(0, 10);
//	kout<<i;
//	i++;
}

