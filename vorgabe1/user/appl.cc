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
#include "guard/guard.h"
/* Hier muesst ihr selbst Code vervollstaendigen */         
         
/* GLOBALE VARIABLEN */

extern CGA_Stream kout;
/* Hier muesst ihr selbst Code vervollstaendigen */ 
         
void Application::action ()
 {
/* Hier muesst ihr selbst Code vervollstaendigen */ 
	while(1){
		if(guard.avail()){
			guard.enter();
			kout.setpos(30,0);
			kout<<"Dies ist eine Ausgabe!!!";
			guard.retne();
			guard.leave();
		}
	}
 
 }
