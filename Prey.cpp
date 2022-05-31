#include "Prey.h"
#include "Ocean.h"

Prey::~Prey()
{
}

void Prey::process()
{
	Coordinate to;

	to = getNeighCoord(this);
	moveFrom(to, _offset);
}

void Prey::moveFrom(Coordinate to, Coordinate from)
{
	--_time_to_reproduce;
	if (to != from)
	{
		if (_owner.getCell(to) == nullptr)
		{
			this->setOffset(to);
			_owner.swapCell(to, from, this);
		}
		cout.flush();
		if (_time_to_reproduce <= 0)
		{
			_time_to_reproduce = time_to_reproduce;
			reproduce(from);
		}
		else
		{
			Cell* temp = nullptr;
			assignCellAt(from, temp);
		}
	}
}

void Prey::reproduce(Coordinate an_offset)
{
	Prey* temp = new Prey(&_owner, an_offset);
	_owner.setNumPrey(_owner.getNumPrey() + 1);
	assignCellAt(an_offset, temp);
}
