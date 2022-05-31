#include "Predator.h"
#include "Ocean.h"

void Predator::process()
{
	if (--_time_to_feed <= 0)
	{
		assignCellAt(_offset, nullptr);
		_owner.setPredNum(_owner.getNumPred() - 1);
		delete this;
	}
	else
	{
		if (getPreyCoord(this) != nullptr)
		{
			Coordinate to_coord = getPreyCoord(this)->getOffset();
			_owner.setNumPrey(_owner.getNumPrey() - 1);
			assignCellAt(to_coord, nullptr);
			_time_to_feed = time_to_feed;
			moveFrom(to_coord, _offset);

		}
		else
		{

			Coordinate to;

			to = getNeighCoord(this);
			moveFrom(to, _offset);
		}
	} 
}
void Predator::moveFrom(Coordinate to, Coordinate from)
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
			assignCellAt(from, nullptr);
		}
	}
}

void Predator::reproduce(Coordinate an_offset)
{
    Predator* temp = new Predator(&_owner, an_offset);
	_owner.setPredNum(_owner.getNumPred() + 1);
	assignCellAt(an_offset, temp);
}
