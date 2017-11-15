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
	cpu.disable_int();
	Gate* gate = (Gate*)queue.dequeue();
	cpu.enable_int();

	while(gate!=0){

		gate->queued(false);
		gate->epilogue();

		cpu.disable_int();
		gate = (Gate*)queue.dequeue();
		cpu.enable_int();
	}
	 guard.retne();
}

void Guard::relay (Gate* item)
{
	cpu.disable_int();
	queue.enqueue(item);
	item->queued(true);
	cpu.enable_int();
}
