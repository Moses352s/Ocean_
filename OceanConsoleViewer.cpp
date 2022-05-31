
#include "Cell.h"
#include "Ocean.h"
#include <iostream>
#include "OceanConsoleViewer.h"

using namespace std;


void OceanConsoleViewer::displayCells()
{
	for (unsigned row = 0; row < _owner.getNumRows(); row++)
	{
		for (unsigned col = 0; col < _owner.getNumCols(); col++)
		{
			if (_owner.getCell(row,col) != nullptr)
			{
				_owner.getCell(row, col)->display();
			}
			else
			{
				cout << default_image;
			}
		}
		cout << '\n';
	}
}

void OceanConsoleViewer::displayBorder()
{
		cout << '\n';
		for (unsigned col = 0; col < _owner.getNumCols() ; col++)
		{
			cout << "*";
		}
		cout << '\n';
}

void OceanConsoleViewer::run()
{
	//unsigned num_iterations = default_num_iterations;
	unsigned num_iterations = 10;

	for (unsigned iteration = 0; iteration < num_iterations; iteration++)
	{
		_visitor.clear();
		
		if (_owner.getNumPred() > 0 && _owner.getNumPrey() > 0)
		{
			for (unsigned row = 0; row < _owner.getNumRows(); row++)
			{
				for (unsigned col = 0; col < _owner.getNumCols(); col++)
				{
					Cell* currentItem =  _owner.getCell(row,col); //_cells[row][col] 

					if (!_visitor.isVisited(currentItem) && currentItem != nullptr)
					{
						currentItem->process();
						_visitor.visit(currentItem);
					}
				}
			}
		}
		displayStats(iteration);
		displayCells();
		displayBorder();
		cout.flush();
		//Sleep(250);
		//system("cls");
	}
	cout << "\n\nEnd of simulation\n";
	cout.flush();
}

void OceanConsoleViewer::displayStats(int iteration)
{
	cout << "\n\n";
	cout << "iteration: " << ++iteration;
	cout << "; obstacles: ";	
	cout << "; predators: " ;
	cout << "; prey: " << _owner.getNumPrey();
	cout.flush();
	displayBorder();
}
