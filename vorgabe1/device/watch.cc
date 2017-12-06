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

void Watch::epilogue (){
	schedule.Scheduler::resume();
}

