#include "TicTacToeLavel2.h"

TicTacToeLavel2::TicTacToeLavel2() :TicTacToe(){
	
		_controller = new BoardControllerGame(this);

}

 void TicTacToeLavel2 ::best_move(char sign_player, int &col, int &row) {

	int i, j, chcount, emptycol, emptyrow;

	for (i = 0; i < 3; i++)
	{
		chcount = 0;
		emptycol = -1;

		// Loop through columns 
		for (j = 0; j < 3; j++)
		{
			// If the specified player is occupying the cell, add to chcount
			if (_bord[i][j] == sign_player)
				chcount++;
			// If specified cell is blank mark the column as empty
			else if (_bord[i][j] == '-')
				emptycol = j;
		}
		// If there are two of the specified player in the row and there is an
		// empty cell, then the empty cell is the winning position
		if (chcount == 2 && emptycol != -1)
		{
			row = i;
			col = emptycol;
			return;
		}
	}
	// The same logic as above applies for columns 
	// check if specified character can win along any column
	for (j = 0; j < 3; j++)
	{
		chcount = 0;
		emptyrow = -1;
		for (i = 0; i < 3; i++)
		{
			if (_bord[i][j] == sign_player)
				chcount++;
			else if (_bord[i][j] == '-')
				emptyrow = i;
		}
		if (chcount == 2 && emptyrow != -1)
		{
			row = emptyrow;
			col = j;
			return;
		}
	}
	// Check if specified character can win along diagonal top-left to bottom-right
	chcount = 0;
	emptyrow = -1;
	emptycol = -1;
	// Loop through the diagonal
	for (i = 0; i < 3; i++)
	{
		if (_bord[i][i] == sign_player)
			chcount++;
		else if (_bord[i][i] == '-')
			emptyrow = emptycol = i;
	}
	if (chcount == 2 && emptyrow != -1 && emptycol != -1)
	{
		row = emptyrow;
		col = emptycol;
		return;
	}
	// Check if specified character can win along diagonal top-right to bottom-left
	chcount = 0;
	emptyrow = -1;
	emptycol = -1;
	// Loop through the diagonal
	for (i = 0; i < 3; i++)
	{
		if (_bord[i][2 - i] == sign_player)
			chcount++;
		else if (_bord[i][2 - i] == '-')
		{
			emptyrow = i;
			emptycol = 2 - i;
		}
	}
	if (chcount == 2 && emptyrow != -1 && emptycol != -1)
	{
		row = emptyrow;
		col = emptycol;
		return;
	}
}
 void TicTacToeLavel2::get_move_cunpoter() {
	int row, col = -1;

	best_move('X', col, row);
	if (col != -1 && row != -1) {
		_bord[row][col] = 'X';
		_move->set_x(row);
		_move->set_y(col);
		Draw_bord();
		_status = LOSS;
	}
	else {
		best_move('O', col, row);
		if (col != -1 && row != -1) {
			_bord[row][col] = 'X';
			_move->set_x(row);
			_move->set_y(col);
			Draw_bord();
			check_equal();
		}
		else {

			get_move_random();
			Draw_bord();
			check_equal();
		}

	}
}