/*****************************************************************************/
/* Betriebssysteme                                                           */


#include "thread/scheduler.h"

void Scheduler::ready(Entrant& that){
	readyList.enqueue(&that);
}

void Scheduler::schedule(){
	go(*(Entrant*)readyList.dequeue());
}

void Scheduler::exit(){
	dispatch(*(Entrant*)readyList.dequeue());
}

void Scheduler::kill(Entrant& that){
	readyList.remove(&that);
}

void Scheduler::resume(){
	readyList.enqueue((Entrant*)active());
	dispatch(*(Entrant*)readyList.dequeue());
}
