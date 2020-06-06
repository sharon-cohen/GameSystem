#include "TicTacToe.h"

 void TicTacToe:: get_move_player() {
	string error = "error again";
	_move->imput();
	int x = _move->get_x();
	int y = _move->get_y();
	while (error == "error again")
	{
		if (x > 2 || x < 0 || y>2 || y < 0)
		{
			cout << "error again";
			_move->imput();
			int x = _move->get_x();
			int y = _move->get_y();
		}
		if (_bord[x][y] != '-') {
			cout << "inalid again";
			_move->imput();
			int x = _move->get_x();
			int y = _move->get_y();
		}

		else {

			_bord[x][y] = 'O';
			Draw_bord();
			error = "valid move";
			check_win();
			if (_status != Win) {
				check_equal();
			}

			return;

		}

	}


}

 void TicTacToe::get_move_random() {
	 int sum = _row * _col;
	 int* row_array = new int[sum];
	 int* col_array = new int[sum];
	 int row_rand;
	 int col_rand;
	 int i = 0;
	 int row = 0;
	 int col = 0;
	 int count = 0;
	 for (; i < _row; i++) {
		 for (int j = 0; j < _col; ++j) {
			 if (_bord[i][j] == '-')
			 {

				 row_array[count] = i;
				 col_array[count] = j;
				 count++;

			 }
		 }
	 }

	 row_rand = rand() % (count - 1);
	 col_rand = col_array[row_rand];
	 row_rand = row_array[row_rand];
	 _move->set_x(row_array[row_rand]);
	 _move->set_y(col_array[col_rand]);
	 _bord[row_rand][col_rand] = 'X';
	 Draw_bord();
 }
 void TicTacToe::check_equal() {

	 bool end = true;
	 for (int i = 0; i < 3; ++i)
		 for (int j = 0; j < 3; ++j) {
			 if (_bord[i][j] == '-') {
				 end = false;
			 }
		 }
	 if (end == true) {
		 _status = EVAN;
	 }
 }
 void TicTacToe::check_win() {
	 int count = 0;
	 for (int i = 0; i < 3; ++i) {
		 count = 0;
		 for (int j = 0; j < 3; ++j) {
			 if (_bord[i][j] == 'O') {
				 count++;
			 }
		 }
	 }

	 if (count == 3) {
		 _status = Win;
		 return;
	 }

	 count = 0;
	 int j = 0;
	 for (int i = 0; i < 3; ++i) {
		 count = 0;
		 for (int j = 0; j < 3; ++j) {
			 if (_bord[j][i] == 'O') {
				 count++;
			 }
		 }
	 }
	 if (count == 3) {
		 _status = Win;
		 return;
	 }
	 count = 0;
	 for (int i = 0; i < 3; i++)
	 {
		 if (_bord[i][i] == 'O')
			 count++;
	 }
	 if (count == 3) {
		 _status = Win;
		 return;
	 }
	 count = 0;
	 for (int i = 0; i < 3; i++)
	 {
		 if (_bord[i][2 - i] == 'O')
			 count++;
	 }
	 if (count == 3) {
		 _status = Win;
		 return;
	 }
	 return;
 }