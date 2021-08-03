#ifndef DATA_H
#define DATA_H
#include <iostream>


struct TurnSnapshot
{
	int turn_total;
	int my_pts;
	int opponent_pts;
	int n_my_turn_rolls;
	
};

struct game_state
{
	int turn_player;
	int p1_total_score;
	int p2_total_score;
	TurnSnapshot turno;

};




#endif