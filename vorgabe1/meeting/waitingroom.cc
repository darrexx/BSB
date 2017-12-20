/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        W A I T I N G R O O M                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Liste von Threads, die auf ein Ereignis warten.                           */
/*****************************************************************************/


#include "meeting/waitingroom.h"

Waitingroom::~Waitingroom(){
    	Customer* c = (Customer*) dequeue();
    	while(c!=0){
    		c->waiting_in(0);
    		c = (Customer*) dequeue();
    	}
    }

void Waitingroom::remove(Customer* customer){
    	Queue::remove(customer);
    }
