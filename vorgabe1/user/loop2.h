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

#ifndef __loop2_include__
#define __loop2_include__

#include "syscall/thread.h"

class Loop2 : public Thread

 {
private:
    Loop2 (const Loop2 &copy); // Verhindere Kopieren
    char stack[8192];

public:
    Loop2():Loop2(&stack[8192]){};

    Loop2(void* tos):Thread(tos){};

    void action ();
 };
extern Loop2 loop2;

#endif
