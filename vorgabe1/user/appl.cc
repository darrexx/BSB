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
#include "guard/secure.h"
#include "user/loop.h"
#include "syscall/guarded_scheduler.h"
         
/* GLOBALE VARIABLEN */

         
void Application::action ()
 {
	while(1){
		{
		Secure secure;
		kout.setpos(30,0);
		kout<<"Dies ist eine Ausgabe!!!";
		}
		//schedule.resume();
	}
 
 }

