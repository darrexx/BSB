/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ S C H E D U L E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Scheduler.                                  */
/*****************************************************************************/

#include "guarded_scheduler.h"
#include "guard/secure.h"
#include "device/watch.h"
#include "machine/plugbox.h"


      void Guarded_Scheduler::ready(Thread& that){
    	  Secure secure;
    	  Scheduler::ready(that);
      }

      void Guarded_Scheduler::exit(){
    	  Secure secure;
    	  Scheduler::exit();
      }

      void Guarded_Scheduler::kill(Thread& that){
    	  Secure secure;
    	  Scheduler::kill(that);
      }

      void Guarded_Scheduler::resume(){
    	  Secure secure;
    	  Watch& watch = (Watch&) plugbox.report(plugbox.TIMER);
    	  watch.interval(watch.interval());
    	  Scheduler::resume();
      }
