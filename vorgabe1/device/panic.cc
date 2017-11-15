/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/
/* Hier muesst ihr selbst Code vervollstaendigen */ 
/* Hier muesst ihr selbst Code vervollstaendigen */ 
#include "device/panic.h" 
#include "device/cgastr.h"
#include "machine/cpu.h"

bool Panic::prologue()
{
    kout.bluescreen("Unbekannter Interrupt gefangen!");
    cpu.halt();
    return false;
}
