/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ O R G A N I Z E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Organizer.                                  */
/*****************************************************************************/

#include "syscall/guarded_organizer.h"
#include "guard/secure.h"
#include "device/watch.h"
#include "machine/plugbox.h"

void Guarded_Organizer::ready(Thread& that){
	Secure secure;
	Organizer::ready(that);
}

void Guarded_Organizer::exit(){
	Secure secure;
	Organizer::exit();
}

void Guarded_Organizer::kill(Thread& that){
	Secure secure;
	Organizer::kill(that);
}

void Guarded_Organizer::resume(){
	Secure secure;
	Watch& watch = (Watch&) plugbox.report(plugbox.TIMER);
	watch.interval(watch.interval());
	Organizer::resume();
}
