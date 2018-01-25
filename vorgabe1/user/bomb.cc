/*
 * bomb.cc
 *
 *  Created on: 24.01.2018
 *      Author: huettn00
 */

#include "bomb.h"
#include "syscall/guarded_buzzer.h"
#include "syscall/guarded_organizer.h"
#include "syscall/guarded_semaphore.h"
#include "machine/cpu.h"

void Bomb::action(){

	Guarded_Buzzer b;
	b.set(5000);

	while(1){
		b.sleep();
		parent->explodeBomb(bomb_x, bomb_y);
		schedule.exit();
	}
}

void Bomb::setPos(short x,short y){
	bomb_x = x;
	bomb_y = y;
}
