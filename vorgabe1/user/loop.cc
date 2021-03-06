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
#include "syscall/guarded_organizer.h"
#include "syscall/guarded_buzzer.h"
#include "syscall/guarded_semaphore.h"
 
void Loop::action ()
 {
	int i=0;
	while(1){


		kout_guard.wait();
		kout.setpos(30,10);
		kout<<"Dies ist Ausgabe Nr2!!! Counter: "<<i;
		kout_guard.signal();

		i++;
		if(i%1000==0){
			Guarded_Buzzer b;
			b.set(1000);
			b.sleep();
		}
//		schedule.resume();

	}

 }

 
