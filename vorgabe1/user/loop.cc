/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 L O O P                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Loop ist ein Thread, der nichts weiter tut als einen Zaehler hochzu-      */
/* zaehlen und dies auf dem Bildschirm anzuzeigen. Zwischendurch gibt er     */
/* den Prozessor ab. Der Scheduler bestimmt dann, welcher Thread als         */
/* naechstes laufen soll.                                                    */
/*****************************************************************************/

#include "user/loop.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "guard/secure.h"
#include "syscall/guarded_scheduler.h"
#include "user/appl.h"
 
void Loop::action ()
 {
	while(1){
		{
		Secure secure;
		kout.setpos(30,10);
		kout<<"Dies ist Ausgabe Nr2!!!";
		}
		//schedule.resume();

	}

 }

 
