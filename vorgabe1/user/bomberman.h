/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 L O O P                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Loop ist ein Thread, der nichts weiter tut als einen Zaehler hochzu-      */
/* zaehlen und dies auf dem Bildschirm anzuzeigen. Zwischendurch gibt er     */
/* den Prozessor ab.                                                         */
/*****************************************************************************/

#ifndef __bomberman_include__
#define __bomberman_include__

#include "syscall/thread.h"
#include "syscall/guarded_semaphore.h"

class Bomberman : public Thread

 {
private:
    Bomberman (const Bomberman &copy); // Verhindere Kopieren
    char stack[90000];
    char field[78][23];
    enum { destructable = 177, indestructable = 178, player = 64 };
	short player_x;
	short player_y;
	void initializeField();
	void showField();

public:
    Bomberman():Bomberman(&stack[90000]){}
    Bomberman(void* tos):Thread(tos){};
    void explodeBomb(short x, short y);
    void action ();
 };

#endif
