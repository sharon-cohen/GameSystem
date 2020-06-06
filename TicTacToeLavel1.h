#pragma once
#include <iostream>
#include "game.h"
#include "TicTacToe.h"
#include <string>
#include <random>
using namespace std;

class TicTacToeLavel1 :public TicTacToe
{
public:
	TicTacToeLavel1() :TicTacToe() {
		_controller = new BoardControllerGame(this);
	
	}
	virtual~TicTacToeLavel1() {};
	virtual void get_move_cunpoter() {
	
		get_move_random();
	}
	


}; 
