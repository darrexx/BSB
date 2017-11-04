/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I C                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interrupt Controller.                                        */
/* Mit Hilfe des PICs koennen Hardware-Unterbrechungen einzeln zugelassen    */
/* oder unterdrueckt werden. Auf diese Weise wird also bestimmt, ob die      */
/* Unterbrechung eines Geraetes ueberhaupt an den Prozessor weitergegeben    */
/* wird. Selbst dann erfolgt eine Aktivierung der Unterbrechungsroutine nur, */
/* wenn der Prozessor bereit ist, auf Unterbrechungen zu reagieren. Dies     */
/* kann mit Hilfe der Klasse CPU festgelegt werden.                          */
/*****************************************************************************/

/* Hier muesst ihr selbst Code vervollstaendigen */ 

#include "machine/pic.h"


void PIC::allow(int interrupt_device){
    char status;

    status = imr_low.inb(); //status lesen

    //buffer mitgeben, damit status sich gemerkt wird
    imr_low.outb(status & ~(1 << interrupt_device)); //status auf allow setzen
}

void PIC::forbid(int interrupt_device){
    char status;

	status = imr_low.inb();
    
    imr_low.outb(status | (1 << interrupt_device));
}

bool PIC::is_masked(int interrupt_device){
    char status;

    status = imr_low.inb();

    if(0 == ((status >> interrupt_device) & 1)){ // position interrupt device vergleichen
        return false;
    }
    else{
        return true;
    }
}