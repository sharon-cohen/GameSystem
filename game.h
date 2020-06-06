#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include "controller.h"

using namespace std;


class  Move
{
public:

	Move(Move &move) :x(move.x), y(move.y) {}
	Move() :x(0), y(0) {}

	~Move() {};
	void imput() {
		cout << "x:";
		cin >> x;
		cout << "y:";
		cin >> y;
	
	}
	 
	void set_arrow(char arr) {
		if (arr == 'w') {
			y--;
			return;
		}
		if (arr == 's') {
			y++;
			return;
		}
		if (arr == 'a') {
			x--;
			return;
		}
		if (arr == 'd') {
			x++;
			return;
		}
	}
	int get_x() { return x; }
	int get_y() { return y; }
	void set_x(int x_) { x = x_; }
	void set_y(int y_) { y = y_; }
	void operator = (const Move& move) {
		x = move.x;
		y = move.y;
	}

private:
	int x;
	int y;
};

class Game
{

protected:
	Controller* _controller;
	Move *_move;
public:
	enum Status
	{
		Win, LOSS, EVAN, PROSES,START
	};
	
	Game() {

		_move = new Move();
		_controller = nullptr;
		_status = START;
	}
	virtual void play() {

		_controller->play();
	}
	virtual void check_end(){}
	virtual void get_move_player() = 0;
	virtual void get_move_cunpoter() = 0;
	virtual Status get_status() {return _status;}
	virtual void Draw_bord() = 0;
	virtual void set_status(string s) { 
		if (s == "prosses")
			_status = PROSES;
		 }
	
	
	virtual ~Game() {
		delete _controller;
		delete _move;
	
	}
	
protected:
	Status _status;

};




