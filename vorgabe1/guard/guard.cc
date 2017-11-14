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

void Guard::leave ()
{
	cpu.enable_int();
	if(avail()){
		enter();
		Gate* gate = (Gate*)queue.dequeue();
		if(gate!=0){
			gate->queued(false);
			gate->epilogue();
			gate = (Gate*)queue.dequeue();
			retne();
			leave();
		}
		else{retne();}
	}
}

void Guard::relay (Gate* item)
{
	cpu.disable_int();
	queue.enqueue(item);
	item->queued(true);
	cpu.enable_int();
}
