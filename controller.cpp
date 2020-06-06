#include "game.h"
#include "controller.h"
#include "TicTacToeLavel1.h"

BoardControllerGame::BoardControllerGame(Game* parent):Controller(parent) {
	

}
void BoardControllerGame::play() {

	while (parent_->get_status() == PROSES || parent_->get_status() == START) {
		
		if (parent_->get_status() == START) {
			parent_->set_status("prosses");
		}
		
		cout << "your turn" << endl<<endl;
		parent_->get_move_player();
		_player = PLAYER_2;
		cout << "AI turn" << endl<< endl;
		parent_->get_move_cunpoter();
		_player = PLAYER_1;
	}
	
	if (parent_->get_status() == Win) {
		cout << "Yaaaaa you win" << endl;
	
	}
	if (parent_->get_status() == LOSS) {
		cout << "Hooo try next time" << endl;

	}
	if (parent_->get_status() == EVAN) {
		cout << "Tense competition.." << endl;

	}
	cout << "Play again!Or try other games";
}
Controller:: ~Controller() {

	delete parent_;
}