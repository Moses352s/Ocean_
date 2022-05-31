#pragma once
#include "Cell.h"

class Obstacle :
    public Cell
{
public:

    Obstacle(Ocean* owner, Coordinate& a_coord) : Cell(owner, a_coord)
    {
        _image = obstacle_image;
    }

    virtual ~Obstacle() {}

    virtual void process()
    {
        
    }

    virtual void display()
    {
        cout << _image;
    }

    virtual void reproduce()
    {

    };

};

