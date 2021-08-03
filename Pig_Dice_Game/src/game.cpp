#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <stdlib.h>
#include "../include/game.h"
#include "../include/data.h"

std::string dice_faces[] = {" ", "\u2680", "\u2681", "\u2682", "\u2683", "\u2684 ", "\u2685"};

int roll(void)
{
	int face;
	srand(time(NULL));
	face = (rand() % 6) + 1;
	std::cout << "\n" << dice_faces[face] << std::endl << std::endl;
	usleep(1500000);
	return face;
}
char human_play(TurnSnapshot & ts)
{	system("clear");
	std::cout << "\033[1;32mYou \033[0m" << " have: " << ts.turn_total << " points in this turn \n";
	std::cout << "\033[1;32mYou \033[0m" << " have: " << ts.my_pts << " in total score \n";
	std::cout << "\033[1;32mYou \033[0m" << " plays: " << ts.n_my_turn_rolls << " times in this turn \n";
	std::cout << "The "<< "\033[1;31mAI \033[0m"  << " have: " << ts.opponent_pts << " in total score\n\n";
	char play;
	std::cout << "Type: 'r' to roll \nor 'h' to hold \n";
	std::cin >> play;
	return play;
}

char ia_play(TurnSnapshot & ts)
{
	system("clear");
	std::cout << "The " << "\033[1;31mAI \033[0m" << " have: " << ts.turn_total << " points this turn\n";
	std::cout << "The " << "\033[1;31mAI \033[0m" << " have: " << ts.my_pts << " in total score \n";
	std::cout << "The "<<"\033[1;31mAI \033[0m" << " plays: " << ts.n_my_turn_rolls << " times in this turn \n";
	std::cout << "the " << "\033[1;32mHuman \033[0m" << " have: " << ts.opponent_pts << " in total score\n";
	int event = 5*(pow(5, (ts.n_my_turn_rolls)));
	int amostral_space = 6*(pow(6, (ts.n_my_turn_rolls)));
	float probability = float(event)/float(amostral_space);
	if(((ts.turn_total + ts.my_pts) >= (ts.opponent_pts) || (((ts.opponent_pts) - (ts.turn_total + ts.my_pts)) <= 20)) && ts.opponent_pts <= 75)
	{
		if((probability*100) >= 40)
		{
			usleep(1500000);
			return 'r';	
		} 
		else
		{
			std::cout << "The " << "\033[1;31mAI \033[0m" << " HOLD!\n\n";
			return 'h';
		}
	}
		
	else if(((ts.turn_total + ts.my_pts) < (ts.opponent_pts) && (((ts.opponent_pts) - (ts.turn_total + ts.my_pts)) > 20)) && ts.opponent_pts > 75)
	{
		if((probability*100) >= 25)
		{
			usleep(1500000);
			return 'r';	
		} 
		else
		{
			std::cout << "The " << "\033[1;31mAI \033[0m" << " HOLD!\n\n";
			return 'h';
		}
	}
	else
	{
		if((probability*100) >= 47)
		{
			usleep(1500000);
			return 'r';	
		} 
		else
		{
			std::cout << "The " << "\033[1;31mAI \033[0m" << " HOLD!\n\n";
			return 'h';
		}
	}


}

bool game_over(game_state & gs)
{
	if(gs.p1_total_score >= 100  || gs.p2_total_score >= 100)
	{
		std::cout << "\n\n";
		if(gs.p1_total_score >= 100) std::cout << "\033[1;32mYou \033[0m" << "Win\n\n";
		else if(gs.p2_total_score >= 100) std::cout << "\033[1;31mAI \033[0m" << "Win\n\n";
		return true;
	}
	else
	{
		return false;
	}
}

void call_and_update(game_state & gs)
{
	if(gs.turn_player == 1)
	{
		gs.turno.my_pts = gs.p1_total_score;
		gs.turno.opponent_pts = gs.p2_total_score;
		char play = human_play(gs.turno);
		if(play == 'r')
		{
			int die_face = roll();
			if(die_face != 1)
			{
				gs.turno.turn_total += die_face;
				gs.turno.n_my_turn_rolls++;
			}
			else
			{
				gs.turno.turn_total = 0;
				gs.turn_player = 2;
				gs.turno.n_my_turn_rolls = 0;	
				std::cout << "\033[1;34mPIGGY (´.(o o).`)\n\n\033[0m";
				usleep(2000000);			
			}
		}
		
		else if(play == 'h')
		{
			gs.p1_total_score += gs.turno.turn_total;
			gs.turno.turn_total = 0;
			gs.turno.n_my_turn_rolls = 0;
			gs.turn_player = 2;
		}

		else
		{
			std::cout << "Entrada inválida\n\n";
		}
	}
	else if(gs.turn_player == 2)
	{
		gs.turno.my_pts = gs.p2_total_score;
		gs.turno.opponent_pts = gs.p1_total_score;
		char play = ia_play(gs.turno);
		if(play == 'r')
		{
			int die_face = roll();
			if(die_face != 1)
			{
				gs.turno.turn_total += die_face;
				gs.turno.n_my_turn_rolls++;
			}
			else
			{
				gs.turno.turn_total = 0;
				gs.turn_player = 1;
				gs.turno.n_my_turn_rolls = 0;
				std::cout << "\033[1;34mPIGGY (´.(o o).`)\n\n\033[0m";	
				usleep(2000000);		
			}
		}
		else
		{
			gs.p2_total_score += gs.turno.turn_total;
			gs.turno.my_pts = gs.p2_total_score;
			gs.turno.turn_total = 0;
			gs.turno.n_my_turn_rolls = 0;
			gs.turn_player = 1;
		}

	}
}

void ini(game_state & gs)
{
	gs.turn_player = 1;
	gs.p1_total_score = 0;
	gs.p2_total_score = 0; 
	gs.turno.my_pts = 0; 
	gs.turno.turn_total = 0;
	gs.turno.n_my_turn_rolls = 0;
	std::cout << "\n\n _____________________\n";
	std::cout << "|      PIG DICE       |\n";
	std::cout << " ---------------------\n";
	std::cout << "     (´.(o o).`)\n\n";
	std::cout << "Starting: 10%\n";
	usleep(500000);
	std::cout << "Starting: 37%\n";
	usleep(500000);
	std::cout << "Starting: 74%\n";
	usleep(500000);
	std::cout << "Starting: 100%\n";
	usleep(1500000);

}