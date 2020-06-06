#pragma once


using namespace std;

class Game;
class Controller {
public:
	enum PLAYER
	{
		PLAYER_1, PLAYER_2
	};
protected:
	
	PLAYER _player;
public:
	
	enum Status
	{
		Win, LOSS, EVAN, PROSES, START
	};
	Controller(Game* parent):_player(PLAYER_1),parent_(parent) {};
	
	virtual ~Controller();
	virtual void play() = 0;
	

protected:
	Game* parent_;
	

};

class BoardControllerGame :public Controller {

public:
	
	BoardControllerGame(Game* parent);
	virtual void play();
	virtual ~BoardControllerGame() {};
	
};
