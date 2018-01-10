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


Buzzer::Buzzer(){

}

virtual Buzzer::~Buzzer(){
	bellringer.cancel(this);
}

virtual void Buzzer::ring(){
	Thread* thread = static_cast<Thread*>(dequeue());
	while(thread != 0){
		schedule.wakeup(*thread);
		thread = static_cast<Thread*>(dequeue());
	}
}

void Buzzer::set(int ms){
	bellringer.job(this,ms);
}

void Buzzer::sleep(){
	//TODO
}
