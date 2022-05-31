#pragma once
#include <iostream>
#include "Random.h"
#include "Cell.h"
#include "Constants.h"
#include "Coordinate.h"
#include "Random.h"
#include "Visitor.h"
#include "OceanConsoleViewer.h"
#include "RandomInitializer.h"
#include "OceanViewer.h"

class Ocean 
	
{
public:

	Ocean() : _visitor(max_rows* max_cols)
	{
		
	}

	void initialize();
	
	void run();
	
	void setCell(Coordinate& a_coord, Cell* a_cell)
	{
		_cells[a_coord.getY()][a_coord.getX()] = a_cell;
	}

	void setPredNum(unsigned num_predators)
	{
		_num_predators = num_predators;
	}

	unsigned getNumPred()
	{
		return _num_predators;
	}

	unsigned getNumRows()
	{
		return _num_rows;
	}

	unsigned getNumCols()
	{
		return _num_cols;
	}
	
	unsigned getNumPrey()
	{
		return _num_prey;
	}

	void setNumPrey(unsigned new_col_prey)
	{
		_num_prey = new_col_prey;
	}

	Cell* getCell(unsigned yvalue, unsigned xvalue)
	{
		return _cells[yvalue][xvalue];
	}

	Cell* getCell(Coordinate a_coord)
	{
		return _cells[a_coord.getY()][a_coord.getX()];
	}

	Coordinate north(Cell*);

	Coordinate south(Cell*);

	Coordinate east(Cell*);

	Coordinate west(Cell*);

	void swapCell(Coordinate&, Coordinate&, Cell*);

protected:

private:

	Coordinate getClearFieldCoord();

	void addObstacles();
	void addPredator();
	void addPrey();

	void displayBorder();
	void displayCells();
	void displayStats(int);

	void cleanGameField();
	void initCells();

	unsigned _size;
	unsigned _num_prey;
	unsigned _num_predators;
	unsigned _num_obstacles;
	unsigned _num_rows;
	unsigned _num_cols;

	Random _random;
	RandomInitializer random;
	OceanViewer* _oView;
	Visitor _visitor;
	Cell* _cells[max_rows][max_cols];
};

