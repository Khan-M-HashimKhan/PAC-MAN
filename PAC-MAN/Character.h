#include<iostream>
#include "mygraphics.h"

using namespace std;

class character
{
public:
	int x1, y1, x2, y2;
	bool ept;
public:
	character(int a1, int a2, int b1, int b2)
	{
		x1 = a1;
		y1 = a2;
		x2 = b1;
		y2 = b2;
		ept = false;
	}

	void move_up()
	{
		y1 = y1 - 25;
		y2 = y2 - 25;
	}
	void move_down()
	{
		y1 = y1 + 25;
		y2 = y2 + 25;
	}
	void move_right()
	{
		x1 = x1 + 25;
		x2 = x2 + 25;
	}
	void move_left()
	{
		x1 = x1 - 25;
		x2 = x2 - 25;
	}

	void set_empty()
	{
		ept = true;
	}

	virtual bool ispoint() = 0;
	virtual bool iswall() = 0;
	virtual bool isghost() = 0;
	virtual bool ispower() = 0;
	virtual void print() =0;
};

class pacman :public character
{
public:
	bool alive;
	bool eat_ghost;
public:
	pacman(int a1, int a2, int b1, int b2) :character(a1, a2, b1, b2)
	{
		alive = true;
		eat_ghost = false;
	}
	virtual bool isempty()
	{
		return false;
	}
	void die()
	{
		alive = false;
	}
	void kill()
	{
		eat_ghost = true;
	}

	bool isalive()
	{
		return alive;
	}
	bool ghost_eater()
	{
		return  eat_ghost;
	}

	virtual void print()
	{
		drawEllipse(x1, y1, x2, y2, 255, 255, 80, 255, 255, 80);
	}

	virtual bool ispoint()
	{
		return false;
	}

	virtual bool iswall()
	{
		return false;
	}
	virtual bool isghost()
	{
		return false;
	}
	virtual bool ispower()
	{
		return false;
	}
};
class ghost :public character
{
public:
	ghost(int a1, int a2, int b1, int b2) :character(a1, a2, b1, b2)
	{
	}
	virtual void print()
	{
		if(ept==false)
			drawEllipse(x1, y1, x2, y2, 80, 80, 80, 80, 80, 80);
		else
			drawEllipse(x1, y1, x2, y2, 0, 0, 0, 0, 0, 0);
	}
	virtual bool ispoint()
	{
		return false;
	}
	virtual bool isempty()
	{
		return ept;
	}
	virtual bool iswall()
	{
		return false;
	}
	virtual bool isghost()
	{
		return true;
	}
	virtual bool ispower()
	{
		return false;
	}
};
class wall :public character
{
public:
	wall(int a1, int a2, int b1, int b2) :character(a1, a2, b1, b2)
	{
	}
	virtual void print()
	{
		drawRectangle(x1, y1, x2, y2, 0, 0, 255, 0, 0, 255);
	}
	virtual bool isempty()
	{
		return ept;
	}
	virtual bool ispoint()
	{
		return false;
	}
	virtual bool iswall()
	{
		return true;
	}
	virtual bool isghost()
	{
		return false;
	}
	virtual bool ispower()
	{
		return false;
	}
};
class point : public character
{
public:
	point(int a1, int a2, int b1, int b2) :character(a1, a2, b1, b2)
	{
	}
	virtual void print()
	{
		if (ept==false)
			drawEllipse(x1 + 15, y1 + 15, x2 - 15, y2 - 15, 255, 255, 255, 255, 255, 255);
		else
			drawEllipse(x1, y1, x2, y2, 80, 80, 80, 80, 80, 80);
	}
	virtual bool ispoint()
	{
		return true;
	}
	virtual bool isempty()
	{
		return ept;
	}
	virtual bool iswall()
	{
		return false;
	}
	virtual bool isghost()
	{
		return false;
	}
	virtual bool ispower()
	{
		return false;
	}
};
class power : public character
{
public:
	power(int a1, int a2, int b1, int b2) :character(a1, a2, b1, b2)
	{
	}
	virtual void print()
	{
		if(ept==false)
			drawEllipse(x1 + 5, y1 + 5, x2 - 5, y2 - 5, 0, 255, 0, 0, 255, 0);
		else
			drawEllipse(x1, y1, x2, y2, 80, 80, 80, 80, 80, 80);
	}
	virtual bool isempty()
	{
		return ept;
	}
	virtual bool ispoint()
	{
		return false;
	}
	virtual bool iswall()
	{
		return false;
	}
	virtual bool isghost()
	{
		return false;
	}
	virtual bool ispower()
	{
		return true;
	}
};
