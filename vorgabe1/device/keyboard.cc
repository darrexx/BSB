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
 
void Keyboard::trigger(){
	Key key = key_hit();
	if(key.valid()){
		kout.show(40, 24, key.ascii(), 0x0f);
		unsigned char a = key.scancode();
		if(a==Key::scan::del&&(key.ctrl_left()&&key.alt_left())){
			reboot();
		}
	}

}
