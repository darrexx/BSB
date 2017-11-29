/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            E N T R A N T                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Eine Koroutine, die vom Scheduler verwaltet wird.                         */
/*****************************************************************************/

#ifndef __entrant_include__
#define __entrant_include__

#include "object/queue.h"
#include "thread/coroutine.h"
        
class Entrant : public Chain, public Coroutine
 {
private:
      Entrant (const Entrant &copy); // Verhindere Kopieren

public:
      Entrant(void* tos):Coroutine(tos){};
 };

#endif
