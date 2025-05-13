#include<iostream>
#include"Maze.h"
#include "mygraphics.h"
using namespace std;

int main()
{
	cls();
	showConsoleCursor(false);
	maze m;
	int g1x1 = 125, g1y1 = 50, g1x2 = 150, g1y2 = 75;
	int g2x1 = 350, g2y1 = 50, g2x2 = 375, g2y2 = 75;
	ghost g1(g1x1, g1y1, g1x2, g1y2), g2(g2x1, g2y1, g2x2, g2y2);
	pacman p(225, 250, 225, 250);
	
	m.print_maze();
	bool game = true;


	int ghost_counter=0;
	while (game == true)
	{
		cls();
		if (ghost_counter == 0)
		{
			ghost_counter++;
			m.move_up('G');
			m.move_up('g');
		}
		else if (ghost_counter >= 1 && ghost_counter <= 4)
		{
			ghost_counter++;
			m.move_left('G');
			m.move_right('g');
		}
		else if (ghost_counter >= 7 && ghost_counter <= 10)
		{
			ghost_counter++;
			m.move_right('G');
			m.move_left('g');
		}
		else if (ghost_counter >= 5 && ghost_counter <= 6)
		{
			ghost_counter++;
			m.move_down('G');
			m.move_down('g');
		}
		else if (ghost_counter == 11)
		{
			ghost_counter = 0;
			m.move_up('G');
			m.move_up('g');
		}

		char move = 'w';

		//move=getKey();

		if (move == 'w' || move == 'W')
		{
			m.move_up('Q');
		}
		if (move == 'a' || move == 'A')
		{
			m.move_left('Q');
		}
		if (move == 'd' || move == 'D')
		{
			m.move_right('Q');
		}
		if (move == 's' || move == 'S')
		{
			m.move_down('Q');
		}

		m.print_maze();
		delay(1000);
	}

	delay(10000);
	return 0;
}