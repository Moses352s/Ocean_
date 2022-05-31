#include "Cell.h"
#include "Ocean.h"



void Cell::assignCellAt(Coordinate a_coord, Cell* a_cell)
{
	_owner.setCell(a_coord, a_cell);
}

Coordinate Cell::getNeighCoord(Cell* item)
{

	int rand_world_side = rand() % 3 + 0;

	switch (rand_world_side)
	{
	case 0:
	{
		Coordinate temp(_owner.north(item).getX(), _owner.north(item).getY());

		return temp;
		break;
	}
	case 1:
	{
		Coordinate temp(_owner.south(item).getX(), _owner.south(item).getY());

		return temp;
		break;
	}
	case 2:
	{
		Coordinate temp(_owner.east(item).getX(), _owner.east(item).getY());

		return temp;
		break;
	}
	case 3:
	{
		Coordinate temp(_owner.west(item).getX(), _owner.west(item).getY());

		return temp;
		break;
	}
	default:
	{
		break;
	}
	}
}

/*
	Cell* neigh[4];
	int count = 0;

	if (north() != nullptr)
	{
		if (north()->getImage() == an_image)
		{
			neigh[count++] = north();
		}
	}

	if (south() != nullptr)
	{
		if (south()->getImage() == an_image)
		{
			neigh[count++] = south();
		}
	}

	if (east() != nullptr)
	{
		if (east()->getImage() == an_image)
		{
			neigh[count++] = east();
		}
	}

	if (west() != nullptr)
	{
		if (west()->getImage() == an_image)
		{
			neigh[count++] = west();
		}
	}

	if (count == 0)
	{
		return this;
	}
	else
	{
		if (count == 1)
		{
			return neigh[0];
		}

		return neigh[rand() % (count - 1) + 0];
	}*/


Cell* Cell::getPreyCoord(Cell* item)
{
	Cell* temp = _owner.getCell(_owner.east(item).getY(), _owner.east(item).getX());
	if (temp != nullptr)
	{
		if (temp->getImage() == default_prey_image)
		{
			return temp;
		}

	}
	temp = _owner.getCell(_owner.east(item).getY(), _owner.east(item).getX());

	if (temp != nullptr)
	{
		if (temp->getImage() == default_prey_image)
		{
			return temp;
		}
	}
	temp = _owner.getCell(_owner.east(item).getY(), _owner.east(item).getX());
	if (temp != nullptr)
	{
		if (temp->getImage() == default_prey_image)
		{
			return temp;
		}
	}
	temp = _owner.getCell(_owner.east(item).getY(), _owner.east(item).getX());
	if (temp != nullptr)
	{
		if (temp->getImage() == default_prey_image)
		{
			return temp;
		}
	}

	return nullptr;
}

/*
Coordinate  Cell::getEmptyNeighCoord()
{

	return getNeighWithImage(default_image)->getOffset();
}

Coordinate  Cell::getPreyNeighCoord()
{
	return getNeighCoord(default_prey_image)->getOffset();
}

Coordinate* Cell::getEmptyCell()
{
	Coordinate* neighbors[4];
	int count = 0;

	if (north() == nullptr)
	{

		int yvalue = (_offset.getY() > 0) ? (_offset.getY() - 1) : (_owner.getNumCols() - 1);
		neighbors[count++] = new Coordinate(_offset.getX(), yvalue);
	}
	if (south() == nullptr)
	{
		int yvalue = (_offset.getY() + 1) % (_owner.getNumCols());
		neighbors[count++] = new Coordinate(_offset.getX(), yvalue);
	}

	if (east() == nullptr)
	{
		int xvalue = (_offset.getX() + 1) % (_owner.getNumCols());
		neighbors[count++] = new Coordinate(xvalue, _offset.getY());
	}
	if (west() == nullptr)
	{
		int xvalue = (_offset.getX() > 0) ? (_offset.getX() - 1) : (_owner.getNumCols() - 1);
		neighbors[count++] = new Coordinate(xvalue, _offset.getY());
	}
	if (count == 0)
	{

		return new Coordinate(_offset.getX(), _offset.getY());
	}
	else
	{
		return	neighbors[_owner.getRandom().nextIntBetween(0, count - 1)];			// neighbors[abs(rand() % ((0) - (count - 1)))];
	}
}
*/

void Cell::reproduce(Coordinate a_coord, Cell* a_cell)
{
	_owner.setCell(a_coord, a_cell);
}

Cell* Cell::getCellAt(Coordinate a_coord)
{
	return _owner.getCell(a_coord);
}

void Cell::setOffset(Coordinate& an_offset)
{
	_offset = an_offset;
}

Coordinate& Cell::getOffset()
{
	return _offset;
}
