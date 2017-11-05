/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstraktion einer Interruptvektortabelle. Damit kann man die Adresse der  */
/* Behandlungsroutine fuer jeden Hardware-, Softwareinterrupt und jede       */
/* Prozessorexception festlegen.                                             */
/*****************************************************************************/

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "guard/gate.h"
#include "device/panic.h"

class Plugbox
 {
private:
    Plugbox(const Plugbox &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */ 
    Gate* gates[64];

public:
    Plugbox() : TIMER(32), KEYBOARD(33) {
        for(int i = 0; i < 64; i++){
            gates[i] = &panic;
        }
    }
    int TIMER;
    int KEYBOARD;
    
    void assign(unsigned int slot, Gate& gate);

    Gate& report (unsigned int slot);
 };

#endif
