/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe des "Weckers" koennen Prozesse eine bestimmte Zeit lang         */
/* schlafen und sich dann wecken lassen.                                     */
/*****************************************************************************/

/* INCLUDES */
#include "meeting/buzzer.h"
#include "meeting/bellringer.h"
#include "syscall/guarded_organizer.h"
#include "machine/cpu.h"


Buzzer::Buzzer(){

}

Buzzer::~Buzzer(){
	bellringer.cancel(this);
}

void Buzzer::ring(){
	Thread* thread = static_cast<Thread*>(dequeue());
	while(thread != 0){
		schedule.wakeup(*thread);
		thread = static_cast<Thread*>(dequeue());
	}
}

void Buzzer::set(int ms){
	time = ms;
}

void Buzzer::sleep(){
	bellringer.job(this,time);
	Thread* thread = static_cast<Thread*>(schedule.active());
	schedule.block(*thread, *this);
}
