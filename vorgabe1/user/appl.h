/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __application_include__
#define __application_include__

#include "syscall/thread.h"

class Application : public Thread
 
 {
private:
    Application (const Application &copy); // Verhindere Kopieren
    char stack[8192];
    char buffer[4000];
	int counter=0;
    void printNotFoundCommand();
    void checkKnownCommands();

public:
    Application():Application(&stack[8192]){};

    Application(void* tos):Thread(tos){};
          
    void action ();
 };

extern Application	app;

#endif
