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

	Bomb bomb_5(this);
	Bomb bomb_6(this);
	Bomb bomb_7(this);
	Bomb bomb_8(this);
	Bomb bomb_9(this);
	score = 0;
	startScreen();

	while(1){
		char c = board.getkey().ascii();

		if(gameOverFlag){
			c = ' ';
			startScreen();
			score = 0;
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
			case 'k':
				if(multiplayerFlag){
					if(field[player2_x][player2_y+1] == ' '){
						if(bombField[player2_x][player2_y]){
							field[player2_x][player2_y] = bomb;
						}
						else{
							field[player2_x][player2_y] = ' ';
						}
						++player2_y;
						field[player2_x][player2_y] = player2;
					}
				}
				break;
			case 'j':
				if(multiplayerFlag){
					if(field[player2_x-1][player2_y] == ' '){
						if(bombField[player2_x][player2_y]){
							field[player2_x][player2_y] = bomb;
						}
						else{
							field[player2_x][player2_y] = ' ';
						}
						--player2_x;
						field[player2_x][player2_y] = player2;
					}
				}
				break;
			case 'i':
				if(multiplayerFlag){
					if(field[player2_x][player2_y-1] == ' '){
						if(bombField[player2_x][player2_y]){
							field[player2_x][player2_y] = bomb;
						}
						else{
							field[player2_x][player2_y] = ' ';
						}
						--player2_y;
						field[player2_x][player2_y] = player2;
					}
				}
				break;
			case 'l':
				if(multiplayerFlag){
					if(field[player2_x+1][player2_y] == ' '){
						if(bombField[player2_x][player2_y]){
							field[player2_x][player2_y] = bomb;
						}
						else{
							field[player2_x][player2_y] = ' ';
						}
						++player2_x;
						field[player2_x][player2_y] = player2;
					}
				}
				break;

			case 'q':
				if(!bombField[player_x][player_y]){

//					Bomb* b = static_cast<Bomb*>(player1_bombs.dequeue());
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
			case 'o':
				if(!bombField[player2_x][player2_y]){
//					Bomb* b = static_cast<Bomb*>(player2_bombs.dequeue());
					if(!bomb_5.isActive){
						bombField[player2_x][player2_y] = true;
						bomb_5.setPos(player2_x, player2_y);
						schedule.ready(bomb_5);
					}else if(!bomb_6.isActive){
						bombField[player2_x][player2_y] = true;
						bomb_6.setPos(player2_x, player2_y);
						schedule.ready(bomb_6);
					}else if(!bomb_7.isActive){
						bombField[player2_x][player2_y] = true;
						bomb_7.setPos(player2_x, player2_y);
						schedule.ready(bomb_7);
					}else if(!bomb_8.isActive){
						bombField[player2_x][player2_y] = true;
						bomb_8.setPos(player2_x, player2_y);
						schedule.ready(bomb_8);
					}else if(!bomb_9.isActive){
						bombField[player2_x][player2_y] = true;
						bomb_9.setPos(player2_x, player2_y);
						schedule.ready(bomb_9);
					}
				}
				break;
		}

		showField();
	}
}

void Bomberman::initializeGame(){
	multiplayerFlag = false;
	this->initializeGame(500);
};

void Bomberman::initializeGame(int seed){

//	Bomb bomb_0(this);
//	Bomb bomb_1(this);
//	Bomb bomb_2(this);
//	Bomb bomb_3(this);
//	Bomb bomb_4(this);
//	player1_bombs.enqueue(&bomb_0);
//	player1_bombs.enqueue(&bomb_1);
//	player1_bombs.enqueue(&bomb_2);
//	player1_bombs.enqueue(&bomb_3);
//	player1_bombs.enqueue(&bomb_4);

	Random rand(seed);
	player_x = 20;
	player_y = 6;


	for(int i = 0; i < 40; ++i){
		for(int j = 0; j < 12; ++j){
			bombField[i][j] = false;
			if(i == 0 || i == 39 || j == 0 || j == 11){
				field[i][j] = indestructable;
			}else{
				int number = rand.number() % 10;
				if(number < 3){
					field[i][j] = destructable;
				}else if(number >= 3 && number <= 7){
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
	gameOverFlag = false;
};

void Bomberman::showField(){
	bool finished = true;
	kout_guard.wait();
	kout.clear();
	kout.setpos(20,6);
	for(int j = 0; j < 12; ++j){
		for(int i=0; i<40; ++i){
			if(finished && field[i][j] == char(destructable)){
				finished=false;
			}
			kout<<field[i][j];
			if(i == 39){
				int x,y;
				kout.getpos(x,y);
				kout.setpos(20,y+1);
			}
		}
	}
	kout_guard.signal();
	if(!multiplayerFlag){
		updateScore(0);
		if(finished){
			initializeGame(score);
		}
	}
}

bool Bomberman::checkPlayer1(short x, short y) {
	if (field[x][y] == char(player)) {
		gameOverFlag = true;
		return true;
	} else if (field[x + 1][y] == char(player)) {
		gameOverFlag = true;
		return true;
	} else if (field[x - 1][y] == char(player)) {
		gameOverFlag = true;
		return true;
	} else if (field[x][y + 1] == char(player)) {
		gameOverFlag = true;
		return true;
	} else if (field[x][y - 1] == char(player)) {
		gameOverFlag = true;
		return true;
	}
	return false;
}


bool Bomberman::checkPlayer2(short x, short y) {
	if(field[x][y] == char(player2)){
		gameOverFlag=true;
		return true;
	}else if(field[x+1][y] == char(player2)){
		gameOverFlag=true;
		return true;
	}else if(field[x-1][y] == char(player2)){
		gameOverFlag=true;
		return true;
	}else if(field[x][y+1] == char(player2)){
		gameOverFlag=true;
		return true;
	}else if(field[x][y-1] == char(player2)){
		gameOverFlag=true;
		return true;
	}
	return false;
}

void Bomberman::explodeBomb(short x,short y){
	if(!gameOverFlag){
		bombField[x][y] = false;

//		if(b->isPlayer1){
//			player1_bombs.enqueue(b);
//		}else{
//			player2_bombs.enqueue(b);
//		}

		if(!multiplayerFlag){

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
		}else{

			bool player1ded = checkPlayer1(x, y);
			bool player2ded = checkPlayer2(x, y);
			if(player1ded && player2ded){
				winner = noWinner;
				gameOver();
			}else if(player1ded){
				winner = player2Winner;
				gameOver();
			}else if(player2ded){
				winner = player1Winner;
				gameOver();
			}else{


				if(field[x+1][y] == char(destructable)){
					field[x+1][y] = ' ';
				}
				if(field[x-1][y] == char(destructable)){
					field[x-1][y] = ' ';
				}
				if(field[x][y+1] == char(destructable)){
					field[x][y+1] = ' ';
				}
				if(field[x][y-1] == char(destructable)){
					field[x][y-1] = ' ';
				}
				field[x][y] = ' ';
				showField();
			}
		}
	}
}

void Bomberman::gameOver(){
	kout_guard.wait();
	kout.clear();
	kout.setpos(35,11);
	kout<<"Game Over";

	if(!multiplayerFlag){
		kout.setpos(33,13);
		kout<<"score: "<<score;
	}else{
		switch(winner){
			case noWinner:
				kout.setpos(34,13);
				kout<<"it's a draw!";
				break;
			case player1Winner:
				kout.setpos(33,13);
				kout<<"Player 1 wins!";
				break;
			case player2Winner:
				kout.setpos(33,13);
				kout<<"Player 2 wins!";
				break;
		}
	}

	kout.setpos(20,15);
	kout<<"Press any key to return to the main menu.";
	kout_guard.signal();
}

void Bomberman::startScreen(){
	kout_guard.wait();
	kout.clear();

	kout.setpos(36, 0);
	kout<<"Bomberman";

	kout.setpos(10,3);
	kout<<"In singleplayer mode score points with placing bombs cleverly.";
	kout.setpos(10,4);
	kout<<"Bombs have a 2.5 second timer before they explode.";



	kout.setpos(10,7);
	kout<<"player 1:                 "<<char(player);
	kout.setpos(10,8);
	kout<<"player 2:                 "<<char(player2);
	kout.setpos(10,9);
	kout<<"bombs:                    "<<char(bomb);
	kout.setpos(10,10);
	kout<<"indestructable walls:     "<<char(indestructable);
	kout.setpos(10,11);
	kout<<"destructable walls:       "<<char(destructable);

	kout.setpos(10,14);
	kout<<"Player 1 moves with: 'w','a','s','d' and places bombs with 'q'";
	kout.setpos(10,15);
	kout<<"Player 2 moves with: 'i','j','k','l' and places bombs with 'o'";


	kout.setpos(10,18);
	kout<<"Press 'Enter' to start a singleplayer game.";
	kout.setpos(10,19);
	kout<<"Press 'm' to start a multiplayer game.";
	kout.setpos(10,20);
	kout<<"Press 'Backspace' to exit.";

	kout_guard.signal();

	char c = board.getkey().ascii();
	switch(c){
		case '\n':
			initializeGame();
			break;
		case '\b':
			kout_guard.wait();
			kout.clear();
			kout_guard.signal();
			schedule.ready(*parent);
			schedule.exit();
			break;
		case 'm':
			initializeMultiplayerGame();
			break;
		default:
			startScreen();
	}
}

void Bomberman::initializeMultiplayerGame(){
	multiplayerFlag = true;
	this->initializeMultiplayerGame(500);
}

void Bomberman::initializeMultiplayerGame(int seed){

//	Bomb bomb_0(this);
//	Bomb bomb_1(this);
//	Bomb bomb_2(this);
//	Bomb bomb_3(this);
//	Bomb bomb_4(this);
//	player1_bombs.enqueue(&bomb_0);
//	player1_bombs.enqueue(&bomb_1);
//	player1_bombs.enqueue(&bomb_2);
//	player1_bombs.enqueue(&bomb_3);
//	player1_bombs.enqueue(&bomb_4);


//	Bomb bomb_5(this);
//	Bomb bomb_6(this);
//	Bomb bomb_7(this);
//	Bomb bomb_8(this);
//	Bomb bomb_9(this);
//	player2_bombs.enqueue(&bomb_5);
//	player2_bombs.enqueue(&bomb_6);
//	player2_bombs.enqueue(&bomb_7);
//	player2_bombs.enqueue(&bomb_8);
//	player2_bombs.enqueue(&bomb_9);

	Random rand(seed);
	player_x = 10;
	player_y = 6;
	player2_x = 30;
	player2_y = 6;


	for(int i = 0; i < 40; ++i){
		for(int j = 0; j < 12; ++j){
			bombField[i][j] = false;
			if(i == 0 || i == 39 || j == 0 || j == 11){
				field[i][j] = indestructable;
			}else{
				int number = rand.number() % 10;
				if(number < 3){
					field[i][j] = destructable;
				}else if(number >= 3 && number <= 7){
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


	field[player2_x-1][player2_y-1] = indestructable;
	field[player2_x-1][player2_y] = ' ';
	field[player2_x-1][player2_y+1] = indestructable;
	field[player2_x][player2_y-1] = ' ';
	field[player2_x][player2_y] = player2;
	field[player2_x][player2_y+1] = ' ';
	field[player2_x+1][player2_y-1] = indestructable;
	field[player2_x+1][player2_y] = ' ';
	field[player2_x+1][player2_y+1] = indestructable;

	showField();
	gameOverFlag = false;
}

void Bomberman::updateScore(int change){
	score +=change;
	kout_guard.wait();
	kout.setpos(20,5);
	kout<<"Score:"<<score;
	kout_guard.signal();
}

