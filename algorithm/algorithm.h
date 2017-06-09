#ifndef ALGORITHM_H
#define ALGORITHM_H
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<vector>

struct MatchState
{
	int state[15][15]; 
	MatchState()
	{
		for (int i = 0; i < 15 * 15; ++i)
		{
			state[i / 15][i % 15] = 0;
		}
	}
};

struct Action
{
	int row, col;
	Action()
	{
		row = -1;
		col = -1;
	}
	Action(int r, int c)
	{
		row = r;
		col = c;
	}
};

void miniMaxSearchForFive(const MatchState& currentState, int& r, int& c);
int guarantee(const MatchState& currentState, int& r, int& c);

class GameJudge{
public:

	GameJudge();

	void makeAMove(const int& r, const int& c, const int player);	
	//player = 1 for computer, play = -1 for human
	int checkGameStatus();
	/*	Return game status
	1 for computer wins
	-1 for human wins
	0 for draw
	2 in the play
	*/
	void humanInput(int& r, int& c);
	void printStatus(const int player, const int status);
	MatchState getGameStatus();
private:
	MatchState gameState;
};


#endif 