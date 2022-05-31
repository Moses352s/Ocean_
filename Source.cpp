#include <iostream>
#include "OceanConsoleViewer.h"
#include "Ocean.h"

using namespace std; // TODO: pascal casing




int main()
{
	//OceanConsoleViewer* viewOcean = new OceanConsoleViewer();
	Ocean* ocean = new Ocean();
	ocean->initialize();
	ocean->run();

	return 0;
}