#pragma once
#include <iostream>
#include "Cell.h"

class Visitor
{

public:
	Visitor(int size)  
	{
		_size = size;
		_lastIndex = 0;
		_visitedCell = new Cell*[_size];
	}

	void visit(Cell* item)
	{
		_visitedCell[_lastIndex++] = item;
	}

	bool isVisited(Cell* item)
	{
		bool result = false;

		for (int i = _lastIndex - 1; i >= 0; i--)
		{
			if (item==_visitedCell[i])
			{
				result = true;
				break;
			}
		}

		return result;
	}

	void clear()
	{
		_lastIndex = 0;
	}

private: 
	Cell** _visitedCell;
	int _size;
	int _lastIndex;
	
};

