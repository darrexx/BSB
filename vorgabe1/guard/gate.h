/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Klasse von Objekten, die in der Lage sind, Unterbrechungen zu behandeln.  */
/*****************************************************************************/

#ifndef __Gate_include__
#define __Gate_include__

#include "object/chain.h"

class Gate : public Chain {
private:
	bool listed;

public:
//    virtual void trigger() = 0;
    virtual bool prologue (){return false;}
    virtual void epilogue () {}
    inline void queued (bool q){listed = q;}
    inline bool queued (){return listed;}
};
                
#endif
