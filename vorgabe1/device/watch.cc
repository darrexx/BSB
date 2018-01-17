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
#include "syscall/guarded_organizer.h"
#include "meeting/bellringer.h"

void Watch::windup (){
    plugbox.assign(Plugbox::TIMER, *this);
    pic.allow(PIC::timer);
}

bool Watch::prologue (){
	return true;
}

void Watch::epilogue (){
	if(i%20){
		schedule.Scheduler::resume();
		i=0;
	}
	bellringer.check();
	++i;
}

