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
    char field[40][12];
    bool bombField[40][12];
    enum { destructable = 177, indestructable = 178, player = 64, bomb = 235};
	short player_x;
	short player_y;
	bool gameOverFlag;
	long score;
	Thread* parent;
	void startScreen();
	void initializeGame();
	void showField();
	void gameOver();
	void updateScore(int change);

public:
    Bomberman(Thread* parent):Bomberman(&stack[90000]){
    	this->parent = parent;
    }
    Bomberman(void* tos):Thread(tos){};
    void explodeBomb(short x, short y);
    void action ();
 };

#endif
