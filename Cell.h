#pragma once
#include <iostream>
#include "Coordinate.h"
#include "Constants.h"


using namespace std;

class Ocean;

class Cell 
	
{

public:

	Cell(Ocean* owner, Coordinate& a_coord) : _offset(a_coord), _image(default_image), _owner(*owner)
	{
		
	}

	virtual ~Cell() {}

	virtual void process() = 0;

	virtual void display() 
	{
		
		
		cout << _image;
	} //вынести в отдельный клас OceanConsoleViewer

	virtual char getImage()
	{
		return _image;
	}
	
	Coordinate& getOffset();
	
	
	Coordinate getNeighCoord(Cell* item);

	void assignCellAt(Coordinate a_coord, Cell* a_cell);

	void reproduce(Coordinate, Cell*);
	
	Cell* getCellAt(Coordinate);

	void setOffset(Coordinate& an_offset);
	
	Cell* getPreyCoord(Cell*);

protected:

	Coordinate _offset;
	char _image;
	Ocean& _owner;
	
private:

};
