/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Der "Gloeckner" wird im Rahmen der Timer-Epilog Bearbeitung aktiviert.    */
/* Er prueft, ob irgendwelche Glocken (Bell-Objekte) laeuten muessen. Die    */
/* Glocken befinden sich in einer Queue, die der Gloeckner verwaltet.        */
/*****************************************************************************/

#include "meeting/bellringer.h"


void Bellringer::check(){
	Bell* bell = static_cast<Bell*>(head);

	if(bell==0){return;}

	bell->tick();
	while(bell != 0 && bell->run_down()){
		remove(bell);
		bell->ring();
		bell = static_cast<Bell*>(head);
	}
}

void Bellringer::job(Bell *bell,int ticks){
	Bell* other = static_cast<Bell*>(head);
	Bell* prev = 0;

	while(other != 0 && other->wait()<ticks){
		ticks -= other->wait();
		prev = other;
		other= static_cast<Bell*>(other->next);
	}

	if(prev == 0){
		insert_first(bell);
	}else{
		insert_after(prev, bell);
	}

	if(other != 0){
		other->wait(other->wait()-ticks);
		other = static_cast<Bell*>(other->next);
	}

	bell->wait(ticks);
}

void Bellringer::cancel(Bell *bell){
	Bell* next = static_cast<Bell*>(bell->next);
	if(next != 0){
		next->wait(next->wait() + bell->wait());
	}
	remove(bell);
}

