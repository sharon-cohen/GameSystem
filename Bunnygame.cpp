#include "Bunnygame.h"
BunnyGame::BunnyGame(int steps) :BoardGame(9, 9), _steps(steps) {
	_move_play2 = new Move();

	cout << "start the game- YOU HAVE-" << _steps << " " << " steps" << endl;
	cout << "button" << endl;
	draw_rect();
	int x = rand() % _row;
	int y = rand() % _row;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	_bord[y][x] = 'B';

	_move_play2->set_x(x);
	_move_play2->set_y(y);
	x = (rand() % _row);
	y = (rand() % _row);
	while (_bord[y][x] == 'B')
	{
		x = rand() % _row;
		y = rand() % _row;
	}
	_move->set_x(x);
	_move->set_y(y);
	_bord[y][x] = 'K';
	Draw_bord();
}

void BunnyGame:: get_move_player() {

	_bord[_move->get_y()][_move->get_x()] = '-';
	cout << "your steps " << _steps << endl;
	set_arrow();
	_move->set_arrow(_arrow);

	check_win();
	_steps--;
	if (_status != Win) {
		check_loss();
	}
	_bord[_move->get_y()][_move->get_x()] = 'K';
	Draw_bord();
}
void BunnyGame:: draw_rect()
{

	cout << "       +---+" << endl << "       | w |" << endl << "       +---+" << endl;

	for (int i = 0; i < 3; i++) {

		cout << " +";
		for (int i = 0; i < 4 - 1; i++)
		{
			cout << "-";
		}
		cout << "+";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{

		cout << " |";
		for (int j = 0; j < 4 - 1; j++)
		{
			if (j == 1) {
				if (i == 0)
					cout << 'a';
				if (i == 1)
					cout << 's';
				if (i == 2)
					cout << 'd';
			}
			else {
				cout << " ";
			}
		}
		cout << "|";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{

		cout << " +";
		for (int i = 0; i < 4 - 1; i++)
		{
			cout << "-";
		}

		cout << "+";
	}
	cout << endl;
}
void BunnyGame::set_arrow() {
	cin >> _arrow;
	cout << "fsdf";
	cout << _move->get_x() << endl;
	cout << _move->get_y() << endl;
	while (_arrow != 'w' && _arrow != 'a' &&_arrow != 's' &&_arrow != 'd'
		|| (_arrow == 'w'&& _move->get_y() == 0) || (_arrow == 's' && _move->get_y() == 8)
		|| (_arrow == 'a'&& _move->get_x() == 0) || (_arrow == 'd'&& _move->get_x() == 8)) {
		cout << "again" << endl;
		cin >> _arrow;

	}


}