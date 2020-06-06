#include "BoardGame.h"
#include "ConsolGame.h"


BoardGame::BoardGame(int row, int col):ConsolGame(), _row(row), _col(col) {

	_bord = new char*[_row];
	for (int i = 0; i < _row; ++i)
	{
		_bord[i] = new char[_col]; // allocate memory for columns in each row
	}
	for (int i = 0; i < _row; ++i) {
		for (int j = 0; j < _col; ++j) {
			_bord[i][j] = '-';

		}

	}

}

 void BoardGame::Draw_bord() {
	cout << "  ";
	for (int i = 0; i < _row; i++) {
		cout << " " << i;
	}

	for (int i = 0; i < _row; ++i) {
		cout << endl;
		cout << i << " ";
		for (int j = 0; j < _col; ++j) {
			cout << " " << _bord[i][j];
		}
	}

	cout << endl;
}