/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               B U Z Z E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Mit Hilfe des "Weckers" koennen Prozesse eine bestimmte Zeit lang         */
/* schlafen und sich dann wecken lassen.                                     */
/*****************************************************************************/

#ifndef __Buzzer_include__
#define __Buzzer_include__

#include "meeting/waitingroom.h"
#include "meeting/bell.h"

class Buzzer:public Waitingroom, public Bell
{
private:
    Buzzer(const Buzzer &copy); // Verhindere Kopieren
    long time;
public:
    Buzzer();
    virtual ~Buzzer();
    virtual void ring();
    void set(int ms);
    void sleep();
};

#endif
