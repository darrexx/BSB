/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                G U A R D                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe dieser Klasse koennen Aktivitaeten, die einen kritischen        */
/* Abschnitt betreffen, der mit einem Guard-Objekt geschuetzt ist, mit       */
/* Unterbrechungsbehandlungsroutinen synchronisiert werden, die ebenfalls    */
/* auf den kritischen Abschnitt zugreifen.                                   */
/*****************************************************************************/

#include "guard.h"
#include "machine/cpu.h"
#include "gate.h"
#include "device/cgastr.h"
#include "guard/secure.h"

void Guard::leave ()
{

	Gate* gate;

	while(1){

		cpu.disable_int();
		gate = (Gate*)queue.dequeue();
		if(gate==0){
			guard.retne();
			cpu.enable_int();
			return;
		}
		cpu.enable_int();

		gate->epilogue();
		gate->queued(false);
	}
}

void Guard::relay (Gate* item)
{

	if(!item->queued()){
		queue.enqueue(item);
		item->queued(true);
		cpu.enable_int();
		if(guard.avail()){
			Secure();
		}
	}
}
