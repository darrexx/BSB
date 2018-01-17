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
#include "syscall/guarded_organizer.h"
#include "syscall/guarded_keyboard.h"
         
/* GLOBALE VARIABLEN */

         
void Application::action ()
 {
	int i=0;
	while(1){
		char c = board.getkey().ascii();
		{
		Secure secure;
		kout.setpos(30,0);
		kout<<"Dies ist eine Ausgabe!!! Key: "<<c<<i;
		if(i==10){
			schedule.Scheduler::kill(loop);
		}
		}
		i ++;
//		schedule.resume();
	}
 
 }

