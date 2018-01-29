/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

/* INCLUDES */

#include "user/appl.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "syscall/guarded_organizer.h"
#include "syscall/guarded_keyboard.h"
#include "syscall/guarded_semaphore.h"
#include "user/bomberman.h"
         
/* GLOBALE VARIABLEN */

         
void Application::action ()
 {
	kout_guard.wait();
	kout.setpos(0,0);
	kout<<">";
	kout_guard.signal();

	while(1){
		Key k = board.getkey();
		if(k.valid()){
			char c = k.ascii();
			switch(c){
				case'\b':
					if(counter>0){
						int x,y;
						kout.getpos(x,y);

						kout_guard.wait();
						kout.setpos(x-1,y);
						kout<<' ';
						kout.setpos(x-1,y);
						kout_guard.signal();

						--counter;
						buffer[counter] = ' ';
					}
					break;
				case '\n':
					kout_guard.wait();
					kout<<endl;
					kout_guard.signal();

					checkKnownCommands();

					int x,y;
					kout_guard.wait();
					kout.getpos(x, y);
					if(x != 0||y != 0){
						kout<<endl;
					}
					kout<<">";
					kout_guard.signal();

					counter = 0;
					break;
				default:
					buffer[counter] = c;
					++counter;

					kout_guard.wait();
					kout<<c;
					kout_guard.signal();
			}
		}
	}
 
 }

void Application::printNotFoundCommand()
{
	kout_guard.wait();
	kout<<"Befehl \"";
	kout_guard.signal();

	for(int i=0; i<counter; ++i){
		kout<<buffer[i];
	}

	kout_guard.wait();
	kout<<"\" nicht gefunden";
	kout_guard.signal();
}

void Application::checkKnownCommands()
{
	if(counter == 4 && buffer[0] == 'h' && buffer[1] == 'e' && buffer[2] == 'l' && buffer[3] == 'p'){
		kout_guard.wait();
		kout<<	"help                  --shows available commands"<<endl<<
				"clear                 --clears the screen"<<endl<<
				"bomberman             --starts the \"Bomberman\" game";
		kout_guard.signal();
	}else if(counter == 5 && buffer[0] == 'c' && buffer[1] == 'l' && buffer[2] == 'e' && buffer[3] == 'a'&& buffer[4] == 'r'){
		kout_guard.wait();
		kout.clear();
		kout_guard.signal();
	}else if(counter == 9 && buffer[0] == 'b' && buffer[1] == 'o' && buffer[2] == 'm' && buffer[3] == 'b' && buffer[4] == 'e' && buffer[5] == 'r' && buffer[6] == 'm' && buffer[7] == 'a' && buffer[8] == 'n'){
		kout_guard.wait();
		kout<<"starting Bomberman ...";
		kout_guard.signal();
		Bomberman bomb(this);
		schedule.ready(bomb);
		schedule.exit();
	}else{
		printNotFoundCommand();
	}
}
