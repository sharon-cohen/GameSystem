#include "BunnyGameLeval2.h"

 void BunnyGameLavel2:: get_move_cunpoter() {

	_bord[_move_play2->get_y()][_move_play2->get_x()] = '-';
	if (check_hazard() == false) {
		int x = (rand() % 9);
		int y = (rand() % 9);
		while (_bord[y][x] == 'K')
		{
			int x = (rand() % 9);
			int y = (rand() % 9);
		}

		_bord[y][x] = 'B';
		_move_play2->set_x(x);
		_move_play2->set_y(y);

	}
	Draw_bord();
}
 bool BunnyGameLavel2::check_hazard() {
	bool tmp = false;
	if (_move_play2->get_x() != 8) {
		if (_bord[_move_play2->get_y()][_move_play2->get_x() + 1] == 'K') {
			_move_play2->set_arrow('a');
			tmp = true;
		}

	}
	if (_move_play2->get_x() != 0) {
		if (_bord[_move_play2->get_y()][_move_play2->get_x() - 1] == 'K') {
			_move_play2->set_arrow('d');
			tmp = true;
		}

	}
	if (_move_play2->get_y() != 0) {
		if (_bord[_move_play2->get_y() - 1][_move_play2->get_x()] == 'K') {
			_move_play2->set_arrow('s');
			tmp = true;
		}
	}
	if (_move_play2->get_y() != 8) {
		if (_bord[_move_play2->get_y() + 1][_move_play2->get_x()] == 'K') {
			_move_play2->set_arrow('w');
			tmp = true;
		}
	}
	if (tmp == true) {
		_bord[_move_play2->get_y()][_move_play2->get_x()] = 'B';
		return true;
	}

	return false;
}