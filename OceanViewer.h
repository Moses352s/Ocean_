#include <iostream>
#include "Visitor.h"


class Ocean;

#pragma once
class OceanViewer
{
protected:
	Ocean& _owner;
	Visitor _visitor;
public:
	virtual void setOcean(Ocean*) = 0;
	virtual void setSize() = 0;
	virtual void initCells() = 0;
	virtual void displayStats(int) = 0;
	virtual void displayCells() = 0;
	virtual void displayBorder() = 0;
	virtual void run() = 0;

};

