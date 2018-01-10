/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            K E Y B O A R D                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturtreiber.                                                          */
/*****************************************************************************/

#ifndef __Keyboard_include__
#define __Keyboard_include__

#include "machine/keyctrl.h"
#include "guard/gate.h"
#include "machine/key.h"
#include "machine/plugbox.h"
#include "machine/pic.h"
#include "meeting/semaphore.h"
 
class Keyboard : public Gate, public Keyboard_Controller    
{        
private:
      Keyboard (const Keyboard &copy); // Verhindere Kopieren
      Key keyHit;
      Key key;
      Semaphore buffer;
         
public:
      Keyboard():buffer(0){}
 
      // PLUGIN: 'Anstoepseln' der Tastatur. Ab sofort werden Tasten erkannt.
      void plugin ();
      Key getkey();

      bool prologue ();
      void epilogue ();
        
 };

#endif
