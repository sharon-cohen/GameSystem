#pragma once
#include <iostream>
#include "game.h"
#include "TicTacToe.h"
using namespace std;

class TicTacToeLavel2 :public TicTacToe
{
public:
	TicTacToeLavel2();
	virtual ~TicTacToeLavel2() {};
	virtual void best_move(char sign_player, int &col, int &row);
	virtual void get_move_cunpoter();

	
};
