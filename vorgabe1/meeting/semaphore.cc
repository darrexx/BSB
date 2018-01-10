/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

#include "meeting/semaphore.h"
#include "syscall/guarded_organizer.h"


Semaphore::Semaphore(int c):counter(c){

}

void Semaphore::p(){
	if(counter>0){
		--counter;
	}else{
		schedule.Organizer::block(static_cast<Customer&>(*schedule.active()), *this);
	}
}

void Semaphore::v(){
	Customer* c = static_cast<Customer*>(dequeue());
	if(c!=0){
		schedule.Organizer::wakeup(*c);
	}else{
		++counter;
	}
}
