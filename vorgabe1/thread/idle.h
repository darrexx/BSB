/*
 * idle.h
 *
 *  Created on: 17.01.2018
 *      Author: huettn00
 */

#ifndef THREAD_IDLE_H_
#define THREAD_IDLE_H_

#include "syscall/thread.h"

class Idle: public Thread

{
private:
    Idle (const Idle &copy); // Verhindere Kopieren
    char stack[1024];

public:
   Idle():Idle(&stack[1024]){};

   Idle(void* tos):Thread(tos){};

   void action ();
 };
extern Idle idle;

#endif /* THREAD_IDLE_H_ */
