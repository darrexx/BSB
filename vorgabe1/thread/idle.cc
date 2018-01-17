/*
 * idle.cpp
 *
 *  Created on: 17.01.2018
 *      Author: huettn00
 */

#include "idle.h"
#include "machine/cpu.h"
#include "syscall/guarded_organizer.h"

void Idle::action(){
	while(1){
		cpu.idle();
		schedule.resume();
	}
}
