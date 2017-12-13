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

#ifndef __loop_include__
#define __loop_include__

#include "syscall/thread.h"

class Loop : public Thread

 {
private:
    Loop (const Loop &copy); // Verhindere Kopieren
    char stack[8192];

public:
    Loop():Loop(&stack[2048]){};

    Loop(void* tos):Thread(tos){};

    void action ();
 };
extern Loop loop;
 
#endif
