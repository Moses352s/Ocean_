#pragma once
#include <iostream>
#include "Cell.h"

using namespace std;

class Prey :
    public Cell
{
public:

    Prey(Ocean* owner, Coordinate& a_coord) :Cell(owner, a_coord)
    {
        _time_to_reproduce = time_to_reproduce;
        _image = default_prey_image;
        _time_to_feed = time_to_feed;
    }

    virtual ~Prey();

    virtual void process();

    void moveFrom(Coordinate, Coordinate);

    void reproduce(Coordinate an_offset);

private:
    
    unsigned _time_to_reproduce;
    unsigned _time_to_feed;
};
