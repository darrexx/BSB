/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

#include "device/keyboard.h"
#include "machine/plugbox.h"
#include "machine/pic.h"

void Keyboard::plugin(){
    plugbox.assign(Plugbox::KEYBOARD, *this);
    pic.allow(PIC::keyboard);
}
/* Hier muesst ihr selbst Code vervollstaendigen */ 
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 
void Keyboard::trigger(){

}
