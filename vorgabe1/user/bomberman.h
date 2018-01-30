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
    enum { destructable = 176, indestructable = 178, player = 64, bomb = 235, player2 = 36};
    enum {noWinner = 0, player1Winner = 1, player2Winner = 2} winner;
	short player_x;
	short player_y;
	short player2_x;
	short player2_y;
	bool multiplayerFlag;
	bool gameOverFlag;
	long score;
	Thread* parent;
//	Queue player1_bombs;
//	Queue player2_bombs;
	void startScreen();
	void initializeGame();
	void initializeGame(int seed);
	void initializeMultiplayerGame();
	void initializeMultiplayerGame(int seed);
	void showField();
	void gameOver();
	void updateScore(int change);
	bool checkPlayer1(short x, short y);
	bool checkPlayer2(short x, short y);

public:
    Bomberman(Thread* parent):Bomberman(&stack[90000]){
    	this->parent = parent;
    }
    Bomberman(void* tos):Thread(tos){};
    void explodeBomb(short x, short y);
    void action ();
 };

#endif
