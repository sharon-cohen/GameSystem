#pragma once
#include <iostream>
#include "Bunnygame.h"
using namespace std;


class BunnyGameLavel1 :public BunnyGame
{
public:
	BunnyGameLavel1() :BunnyGame(25) {
		_controller = new BoardControllerGame(this);
	
	}
	virtual void get_move_cunpoter();
	
	virtual ~BunnyGameLavel1() {};


};