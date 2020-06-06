#include"BunnyGameLeval1.h"
 void BunnyGameLavel1::get_move_cunpoter() {
	_bord[_move_play2->get_y()][_move_play2->get_x()] = '-';
	int x = (rand() % 9);
	int y = (rand() % 9);
	while (_bord[y][x] == 'K')
	{
		x = (rand() % 9);
		y = (rand() % 9);
	}

	_bord[y][x] = 'B';
	_move_play2->set_x(x);
	_move_play2->set_y(y);
	Draw_bord();
}