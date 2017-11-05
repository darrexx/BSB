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

void Panic::trigger()
{
    kout << "Fehlermeldung!" << endl;
    //cpu.halt(); TODO Irgendwie CPU bekannt machen?
}