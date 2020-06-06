#pragma once
#include <iostream>
#include "game.h"
#include"BoardGame.h"
#include <string>
using namespace std;

class TicTacToe :public BoardGame
{
public:
	
	TicTacToe() :BoardGame(3, 3) { }
	~TicTacToe() {};
	virtual void get_move_player();
	virtual void get_move_cunpoter() = 0;
	virtual void get_move_random();
	virtual void check_equal();
	virtual void check_win();
	
};

