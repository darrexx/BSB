/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               S E C U R E                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Secure dient dem Setzen und Freigeben der Sperrvariablen, mit  */
/* der die kritischen Abschnitte des Betriebssystemkerns geschuetzt werden.  */
/* Im Konstruktor der Klasse wird die Sperre gesetzt, im Destruktor wieder   */
/* freigegeben. Dadurch genuegt schon die Deklaration eines Secure Objekts,  */
/* um den gesamten Geltungsbereich als kritischen Abschnitt zu schuetzen.    */
/*****************************************************************************/

#ifndef __Secure_include__
#define __Secure_include__

#include "guard.h"

class Secure{
public:
	inline Secure() {guard.enter();}
	inline ~Secure(){guard.leave();}
};


#endif
