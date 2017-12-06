/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  P I T                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Programmable Interval Timer.                                              */
/*****************************************************************************/

#ifndef __pit_include__
#define __pit_include__

#include "machine/io_port.h"

class PIT
 {
private:
    PIT(const PIT &copy); // Verhindere Kopieren
    int iv;
    const IO_Port ctrl_port;
    const IO_Port count0;
public:
    PIT (int us):ctrl_port(0x43),count0(0x40) {
      interval (us);
    }

    int interval ();
    void interval (int us);
};

#endif
