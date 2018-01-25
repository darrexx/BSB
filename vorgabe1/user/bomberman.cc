/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B O M B E R M A N                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

#include "user/bomberman.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "syscall/guarded_organizer.h"
#include "syscall/guarded_buzzer.h"
#include "syscall/guarded_semaphore.h"
#include "library/random.h"
#include "syscall/guarded_keyboard.h"
#include "user/bomb.h"

void Bomberman::action ()
 {
	initializeField();
	showField();

	while(1){
		char c = board.getkey().ascii();
		switch(c){
			case 'w':
				if(field[player_x][player_y-1] == ' '){
					field[player_x][player_y] = ' ';
					--player_y;
					field[player_x][player_y] = player;
				}
				break;
			case 'a':
				if(field[player_x-1][player_y] == ' '){
					field[player_x][player_y] = ' ';
					--player_x;
					field[player_x][player_y] = player;
				}
				break;
			case 's':
				if(field[player_x][player_y+1] == ' '){
					field[player_x][player_y] = ' ';
					++player_y;
					field[player_x][player_y] = player;
				}
				break;
			case 'd':
				if(field[player_x+1][player_y] == ' '){
					field[player_x][player_y] = ' ';
					++player_x;
					field[player_x][player_y] = player;
				}
				break;
			case '\n':
				Bomb bomb(this);
				bomb.setPos(player_x, player_y);
				schedule.ready(bomb);
		}

		showField();
	}
}

void Bomberman::initializeField(){
	Random rand(500);
	player_x = 40;
	player_y = 12;


	for(int i = 0; i < 78; ++i){
		for(int j = 0; j < 23; ++j){
			if(i == 0 || i == 77 || j == 0 || j == 22){
				field[i][j] = indestructable;
			}else{
				int number = rand.number() % 10;
				if(number < 6){
					field[i][j] = destructable;
				}else if(number >= 6 && number <= 8){
					field[i][j] = ' ';
				}else{
					field[i][j] = indestructable;
				}
			}
		}
	}
	field[39][11] = indestructable;
	field[39][12] = ' ';
	field[39][13] = indestructable;
	field[40][11] = ' ';
	field[40][12] = player;
	field[40][13] = ' ';
	field[41][11] = indestructable;
	field[41][12] = ' ';
	field[41][13] = indestructable;

};

void Bomberman::showField(){
	kout.setpos(0,0);
	for(int j = 0; j < 23; ++j){
		for(int i=0; i<78; ++i){
			kout<<field[i][j];
			if(i == 77){
				kout<<endl;
			}
		}
	}
}

void Bomberman::explodeBomb(short x,short y){
	if(field[x+1][y] == destructable){
		field[x+1][y] = ' ';
	}
	if(field[x-1][y] == destructable){
		field[x-1][y] = ' ';
	}
	if(field[x][y+1] == destructable){
		field[x][y+1] = ' ';
	}
	if(field[x][y-1] == destructable){
		field[x][y-1] = ' ';
	}
}
