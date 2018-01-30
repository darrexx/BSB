/*
 * bomb.h
 *
 *  Created on: 24.01.2018
 *      Author: huettn00
 */

#ifndef USER_BOMB_H_
#define USER_BOMB_H_

#include "syscall/thread.h"
#include "user/bomberman.h"


class Bomb: public Thread {
private:
    Bomb (const Bomb &copy); // Verhindere Kopieren
    Bomb(void* tos):Thread(tos){};
    char stack[2048];
    short bomb_x,bomb_y;
    Bomberman* parent;

public:
    Bomb(Bomberman* parent):Bomb(&stack[2048]){
    	this->parent = parent;
    	isActive = false;
    }

    void action ();
    void setPos(short x, short y);
    void getPos(short &x, short &y);
    bool isActive;
    bool isPlayer1;

};

#endif /* USER_BOMB_H_ */
