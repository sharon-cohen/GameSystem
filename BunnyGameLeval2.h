#pragma once
#include <iostream>
#include "Bunnygame.h"
using namespace std;

class BunnyGameLavel2 :public BunnyGame
{
public:
	BunnyGameLavel2() :BunnyGame(20) {
		_controller = new BoardControllerGame(this);

	}
	virtual void get_move_cunpoter();
	virtual bool check_hazard();
	~BunnyGameLavel2() {};
	
};