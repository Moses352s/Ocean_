#pragma once
#include "OceanViewer.h"
#include <Windows.h>
class OceanConsoleViewer : public OceanViewer
{
public:
	
	//OceanConsoleViewer() {};
	//void setOcean(Ocean*);
	void displayCells();
	void displayBorder();
	void run();
	void displayStats(int);

  
};

