#pragma once
#include <iostream>
#include "controller.h"
#include <vector>
#include"ConsolGame.h"
#include "game.h"
using namespace std;

class BoardGame: public ConsolGame
{
public:
	BoardGame(int row, int col);
	virtual void Draw_bord();
	virtual void check_win() = 0;
	virtual ~BoardGame() {
		for (int i = 0; i < _col; i++) {
			delete _bord[i];
		}
		delete[] _bord;
	}
protected:
	char** _bord;
	int _row;
	int _col;
};
