/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/


#include "machine/pit.h"

int PIT::interval (){
	return iv;
}

void PIT::interval (int us){
	iv=us;
	unsigned int tInterval = us *1000/838;

	ctrl_port.outb(0b00110100);
	count0.outb(tInterval & 0xFF);
	count0.outb((tInterval>>8) & 0xFF);
}
