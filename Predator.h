#pragma once

#include <iostream>
#include <Windows.h>
#include "Cell.h"

using namespace std;
class Predator :
    public Cell
{
public:

    Predator(Ocean* owner, Coordinate a_coord) : Cell(owner, a_coord)
    {
        _time_to_feed = time_to_feed;
        _image = default_pred_image;
        _time_to_reproduce = time_to_reproduce;
    }

    
    virtual ~Predator() {}

    virtual void process();
  
    virtual void display()
    {
        
        cout << _image;
        
    }

    void moveFrom(Coordinate, Coordinate);

protected:

    unsigned _time_to_feed;
    unsigned _time_to_reproduce;

private:

    void reproduce(Coordinate an_offset);
    
};

