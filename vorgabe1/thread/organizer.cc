/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          O R G A N I Z E R                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Ein Organizer ist ein spezieller Scheduler, der zusaetzlich das Warten    */
/* von Threads (Customer) auf Ereignisse erlaubt.                            */
/*****************************************************************************/

#include "thread/organizer.h"

void Organizer::block(Customer& customer, Waitingroom& waitingroom){
	customer.waiting_in(&waitingroom);
	waitingroom.enqueue(&customer);
	schedule();

}

void Organizer::wakeup (Customer& customer){
	customer.waiting_in()->remove(&customer);
	customer.waiting_in(0);
	ready(customer);
}

void Organizer::kill (Customer& that){
	Waitingroom* wait = that.waiting_in();
	if(wait!=0){
		wait->remove(&that);
		that.waiting_in(0);
	}else{
		Scheduler::kill(that);
	}
}
