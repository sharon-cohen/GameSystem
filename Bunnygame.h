#pragma once
#include <iostream>
#include "BoardGame.h"
#include "game.h"
#include <ctime>
#include <cstdlib>

class BunnyGame :public BoardGame
{
protected:
	
	Move* _move_play2;
public:
	BunnyGame(int steps);
	
	virtual void get_move_player();
	void check_loss() {
		if (_steps == 0) {
			_status = LOSS;
		}
	
	}
	virtual void check_win() {
		if (_bord[_move->get_y()][_move->get_x()] == 'B') {
			_status =Win;
		}
	}
	void draw_rect();
	void set_arrow();
	virtual ~BunnyGame() {
		delete _move_play2;
	};

protected:
	int _steps;
	char _arrow;



};