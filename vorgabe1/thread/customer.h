/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         C U S T O M E R                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Ein Thread, der auf ein Ereignis warten kann.                             */
/*****************************************************************************/

#ifndef __customer_include__
#define __customer_include__

#include "thread/entrant.h"
#include "meeting/waitingroom.h"

class Waitingroom;
        
class Customer  : public Entrant
 {
private:
    Customer (const Customer &copy); // Verhindere Kopieren
    Waitingroom* wait;

public:
    Customer(void* tos):Entrant(tos),wait(0){};
    void waiting_in(Waitingroom* w){wait=w;};
    Waitingroom* waiting_in(){return wait;};

};

#endif
