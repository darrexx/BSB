/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
/* Hier muesst ihr selbst Code vervollstaendigen */         
         
/* GLOBALE VARIABLEN */

extern CGA_Stream kout;
/* Hier muesst ihr selbst Code vervollstaendigen */ 
         
void Application::action ()
 {
/* Hier muesst ihr selbst Code vervollstaendigen */ 
	while(1){
		cpu.disable_int();
		kout.setpos(30,0);
		kout<<"Dies ist eine Ausgabe!!!";
		cpu.enable_int();
	}
 
 }
