#include<iostream>
#include<fstream>
#include"Character.h"
#include "mygraphics.h"

using namespace std;

class maze
{
public:

	int x, y, px, py;
	int pr, pc;
	int g1r, g1c, g2r, g2c;
	character ***map;
	int points,maxpoints;

public:
	maze()
	{
		points = 0;
		x = 0;
		y = 0;
		px = 25;
		py = 25;

		map = new character ** [10];
		for (int r = 0; r < 10; r++)
			map[r] = new character * [20];
		fstream fin;
		fin.open("map.txt");
		for (int r = 0; r < 10; r++)
		{
			for (int c = 0; c < 20; c++)
			{
				char f;
				fin.get(f);
				if (f == 'Q')
				{
					pr = r;
					pc = c;
					map[r][c] = new pacman(x,y,px,py);
				}
				if (f == 'G')
				{
					g1r = r;
					g1c = c;
					map[r][c] = new ghost(x, y, px, py);
				}
				if (f == 'g')
				{
					g2r = r;
					g2c = c;
					map[r][c] = new ghost(x, y, px, py);
				}
				if (f == 'W')
				{
					map[r][c] = new wall(x, y, px, py);
				}
				if (f == 'P')
				{
					map[r][c] = new point(x, y, px, py);
					maxpoints++;
				}
				if (f == 'E')
				{
					map[r][c] = new power(x, y, px, py);
					maxpoints++;
				}
				x = x + 25;
				px = px + 25;
			}
			fin.get();
			y = y + 25;
			py = py + 25;
			x = 0;
			px = 25;
		}
	}

	void print_maze()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				map[i][j]->print();
			}
		}

		y = 0;
		py = 25;
		x = 0;
		px = 25;
	}

	void move_up(char c)
	{
		if (c == 'Q')
		{
			if (map[pr-1][pc]->ispoint() || map[pr-1][pc]->ispower() || map[pr-1][pc]->ept)
			{
				swap(map[pr - 1][pc], map[pr][pc]);
				map[pr - 1][pc]->move_up();
				map[pr][pc]->move_down();
				if (map[pr - 1][pc]->ispoint())
				{
					map[pr - 1][pc]->set_empty();
					points++;
				}
				if (map[pr - 1][pc]->ispower())
				{
					map[pr - 1][pc]->set_empty();
					points++;
				}
				pr--;
			}
			if (map[pr - 1][pc]->isghost())
				endgame(false);
			if (points == maxpoints)
				endgame(true);
		}
		if (c == 'G')
		{
			swap(map[g1r - 1][g1c], map[g1r][g1c]);
			map[g1r][g1c]->move_down();
			map[g1r - 1][g1c]->move_up();
			g1r--;
		}
		if (c == 'g')
		{
			swap(map[g2r - 1][g2c], map[g2r][g2c]);
			map[g2r][g2c]->move_down();
			map[g2r-1][g2c]->move_up();
			g2r--;
		}
	}
	void move_down(char c)
	{
		if (c == 'Q')
		{		
			if (map[pr+1][pc]->ispoint() || map[pr+1][pc]->ispower() || map[pr+1][pc]->ept)
			{
				swap(map[pr + 1][pc], map[pr][pc]);
				map[pr + 1][pc]->move_down();
				map[pr][pc]->move_up();
				
				if (map[pr + 1][pc]->ispoint())
				{
					map[pr + 1][pc]->set_empty();
					points++;
				}
				if (map[pr + 1][pc]->ispower())
				{
					map[pr + 1][pc]->set_empty();
					points++;
				}

				pr++;
			}
			if (map[pr + 1][pc]->isghost())
				endgame(false);
			if (points == maxpoints)
				endgame(true);
		}
		if (c == 'G')
		{
			swap(map[g1r + 1][g1c], map[g1r][g1c]);
			map[g1r][g1c]->move_up();
			map[g1r + 1][g1c]->move_down();
			g1r++;
		}
		if (c == 'g')
		{
			swap(map[g2r+1][g2c], map[g2r][g2c]);
			map[g2r][g2c]->move_up();
			map[g2r+1][g2c]->move_down();
			g2r++;
		}
	}
	void move_right(char c)
	{
		if (c == 'Q')
		{
			if (map[pr][pc + 1]->ispoint() || map[pr][pc + 1]->ispower() || map[pr][pc + 1]->ept)
			{
				swap(map[pr][pc + 1], map[pr][pc]);
				map[pr][pc]->move_left();
				map[pr][pc + 1]->move_right();
				
				if (map[pr][pc + 1]->ispoint())
				{
					map[pr][pc + 1]->set_empty();
					points++;
				}
				if (map[pr][pc + 1]->ispower())
				{
					map[pr][pc + 1]->set_empty();
					points++;
				}

				if (map[pr][pc + 1]->isghost())
					endgame(false);
				if (points == maxpoints)
					endgame(true);

				pc++;
			}
			if (map[pr][pc + 1]->isghost())
				endgame(false);
		}
		if (c == 'G')
		{

			swap(map[g1r][g1c + 1], map[g1r][g1c]);
			map[g1r][g1c]->move_left();
			map[g1r][g1c + 1]->move_right();
			g1c++;
		}
		if (c == 'g')
		{
			swap(map[g2r][g2c + 1], map[g2r][g2c]);
			map[g2r][g2c]->move_left();
			map[g2r][g2c+1]->move_right();
			g2c++;
		}
	}
	void move_left(char c)
	{
		if (c == 'Q')
		{
			if (map[pr][pc - 1]->ispoint() || map[pr][pc - 1]->ispower() || map[pr][pc - 1]->ept)
			{
				swap(map[pr][pc - 1], map[pr][pc]);
				map[pr][pc - 1]->move_left();
				map[pr][pc]->move_right();
				
				if (map[pr][pc - 1]->ispoint())
				{
					map[pr][pc - 1]->set_empty();
					points++;
				}
				if (map[pr][pc - 1]->ispower())
				{
					map[pr][pc - 1]->set_empty();
					points++;
				}

				pc--;
			}
			if (map[pr][pc - 1]->isghost())
				endgame(false);
			if (points == maxpoints)
				endgame(true);
		}
		if (c == 'G')
		{
			swap(map[g1r][g1c - 1], map[g1r][g1c]);
			map[g1r][g1c]->move_right();
			map[g1r][g1c - 1]->move_left();
			g1c--;
		}
		if (c == 'g')
		{
			swap(map[g2r][g2c - 1], map[g2r][g2c]);
			map[g2r][g2c]->move_right();
			map[g2r][g2c-1]->move_left();
			g2c--;
		}
	}

	void endgame(bool game)
	{
		cls();
		if (game == false)
			cout << "YOU LOOSE";
		else
			cout << "YOU WIN";
	}

};