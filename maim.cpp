#pragma once
#include <iostream>
#include "game.h"
#include "TicTacToe.h"
#include "TicTacToeLavel1.h"
#include "TicTacToeLavel2.h"
#include "BunnyGameLeval1.h"
#include "BunnyGameLeval2.h"
#include <ctime>

int main() {
	
	
srand((unsigned int)time(NULL));
	
	TicTacToeLavel2* test=new TicTacToeLavel2();
	
	test->play();
	delete test;

}