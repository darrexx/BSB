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
	Bomb bomb_0(this);
	Bomb bomb_1(this);
	Bomb bomb_2(this);
	Bomb bomb_3(this);
	Bomb bomb_4(this);
	startScreen();
	initializeGame();

	//TODO make it more likely for player to game over
	//TODO add multiple stages

	while(1){
		char c = board.getkey().ascii();

		if(gameOverFlag){
			c = ' ';
			startScreen();
			initializeGame();
		}

		switch(c){
			case 'w':
				if(field[player_x][player_y-1] == ' '){
					if(bombField[player_x][player_y]){
						field[player_x][player_y] = bomb;
					}else{
						field[player_x][player_y] = ' ';
					}
					--player_y;
					field[player_x][player_y] = player;
				}
				break;

			case 'a':
				if(field[player_x-1][player_y] == ' '){
					if(bombField[player_x][player_y]){
						field[player_x][player_y] = bomb;
					}else{
						field[player_x][player_y] = ' ';
					}
					--player_x;
					field[player_x][player_y] = player;
				}
				break;

			case 's':
				if(field[player_x][player_y+1] == ' '){
					if(bombField[player_x][player_y]){
						field[player_x][player_y] = bomb;
					}else{
						field[player_x][player_y] = ' ';
					}
					++player_y;
					field[player_x][player_y] = player;
				}
				break;

			case 'd':
				if(field[player_x+1][player_y] == ' '){
					if(bombField[player_x][player_y]){
						field[player_x][player_y] = bomb;
					}else{
						field[player_x][player_y] = ' ';
					}
					++player_x;
					field[player_x][player_y] = player;
				}
				break;

			case '\n':
				if(!bombField[player_x][player_y]){

					//TODO find a better way to have multiple bombs
					if(!bomb_0.isActive){
						bombField[player_x][player_y] = true;
						bomb_0.setPos(player_x, player_y);
						schedule.ready(bomb_0);
					}else if(!bomb_1.isActive){
						bombField[player_x][player_y] = true;
						bomb_1.setPos(player_x, player_y);
						schedule.ready(bomb_1);
					}else if(!bomb_2.isActive){
						bombField[player_x][player_y] = true;
						bomb_2.setPos(player_x, player_y);
						schedule.ready(bomb_2);
					}else if(!bomb_3.isActive){
						bombField[player_x][player_y] = true;
						bomb_3.setPos(player_x, player_y);
						schedule.ready(bomb_3);
					}else if(!bomb_4.isActive){
						bombField[player_x][player_y] = true;
						bomb_4.setPos(player_x, player_y);
						schedule.ready(bomb_4);
					}
				}
				break;
		}

		showField();
	}
}

void Bomberman::initializeGame(){
	Random rand(500);
	score = 0;
	player_x = 20;
	player_y = 6;


	for(int i = 0; i < 40; ++i){
		for(int j = 0; j < 12; ++j){
			bombField[i][j] = false;
			if(i == 0 || i == 39 || j == 0 || j == 11){
				field[i][j] = indestructable;
			}else{
				int number = rand.number() % 10;
				if(number < 4){
					field[i][j] = destructable;
				}else if(number >= 4 && number <= 8){
					field[i][j] = ' ';
				}else{
					field[i][j] = indestructable;
				}
			}
		}
	}
	field[player_x-1][player_y-1] = indestructable;
	field[player_x-1][player_y] = ' ';
	field[player_x-1][player_y+1] = indestructable;
	field[player_x][player_y-1] = ' ';
	field[player_x][player_y] = player;
	field[player_x][player_y+1] = ' ';
	field[player_x+1][player_y-1] = indestructable;
	field[player_x+1][player_y] = ' ';
	field[player_x+1][player_y+1] = indestructable;

	showField();
};

void Bomberman::showField(){
	kout.clear();
	kout.setpos(20,6);
	for(int j = 0; j < 12; ++j){
		for(int i=0; i<40; ++i){
			kout<<field[i][j];
			if(i == 39){
				int x,y;
				kout.getpos(x,y);
				kout.setpos(20,y+1);
			}
		}
	}
	updateScore(0);
}

void Bomberman::explodeBomb(short x,short y){
	bombField[x][y] = false;

	if(field[x][y] == char(player)){
		gameOverFlag=true;
		gameOver();
	}else if(field[x+1][y] == char(player)){
		gameOverFlag=true;
		gameOver();
	}else if(field[x-1][y] == char(player)){
		gameOverFlag=true;
		gameOver();
	}else if(field[x][y+1] == char(player)){
		gameOverFlag=true;
		gameOver();
	}else if(field[x][y-1] == char(player)){
		gameOverFlag=true;
		gameOver();
	}else{


		if(field[x+1][y] == char(destructable)){
			field[x+1][y] = ' ';
			updateScore(5);
		}else{
			updateScore(-1);
		}
		if(field[x-1][y] == char(destructable)){
			field[x-1][y] = ' ';
			updateScore(5);
		}else{
			updateScore(-1);
		}
		if(field[x][y+1] == char(destructable)){
			field[x][y+1] = ' ';
			updateScore(5);
		}else{
			updateScore(-1);
		}
		if(field[x][y-1] == char(destructable)){
			field[x][y-1] = ' ';
			updateScore(5);
		}else{
			updateScore(-1);
		}

		field[x][y] = ' ';
		showField();
	}
}

void Bomberman::gameOver(){
	kout.clear();
	kout.setpos(35,11);
	kout<<"Game Over";
	kout.setpos(35,13);
	kout<<"score: "<<score;
	kout.setpos(20,15);
	kout<<"Press any key to return to the main menu.";
}

void Bomberman::startScreen(){
	gameOverFlag = false;
	kout.clear();

	kout.setpos(36, 0);
	kout<<"Bomberman";

	kout.setpos(20,5);
	kout<<"Move with: 'w','a','s','d'.";
	kout.setpos(20,6);
	kout<<"Place up to 5 bombs with: 'Enter.";
	kout.setpos(20,7);
	kout<<"Bombs have a 5 second timer before they explode.";


	kout.setpos(20,10);
	kout<<"you:                      "<<char(player);
	kout.setpos(20,11);
	kout<<"bombs:                    "<<char(bomb);
	kout.setpos(20,12);
	kout<<"indestructable walls:     "<<char(indestructable);
	kout.setpos(20,13);
	kout<<"destructable walls:       "<<char(destructable);


	kout.setpos(20,17);
	kout<<"Press 'Enter' to start.";
	kout.setpos(20,18);
	kout<<"Press 'Backspace' to exit.";

	char c = board.getkey().ascii();
	switch(c){
		case '\n':
			initializeGame();
			break;
		case '\b':
			kout.clear();
			schedule.ready(*parent);
			schedule.exit();
			break;
		default:
			startScreen();
	}
}

void Bomberman::updateScore(int change){
	//TODO fix position bug
	score +=change;
	kout.setpos(20,5);
	kout<<"Score:"<<score;
}

