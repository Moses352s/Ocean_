#pragma once
#include <iostream>

using namespace std;

class Coordinate
{
public:
	Coordinate(unsigned a_x, unsigned a_y) : x(a_x), y(a_y) {};
	Coordinate() :x(0), y(0) {};
	Coordinate(Coordinate& a_coord) 
	{
		x = a_coord.x;
		y = a_coord.y;
	};
	~Coordinate() {};

	unsigned getX()
	{
		return x;
	};

	unsigned getY()
	{
		return y;
	}

	void setX(unsigned a_x)
	{
		x = a_x;
	}

	void setY(unsigned a_y)
	{
		y = a_y;
	}

	bool operator==(Coordinate& c)
	{
		return(x == c.x && y == c.y);
	}

	bool operator!=(Coordinate& c)
	{
		
		return(x != c.x || y != c.y);
	}

private:
	unsigned x;
	unsigned y;
};

