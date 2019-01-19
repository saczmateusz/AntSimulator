#include "definitions.h"
#include "Simulation/Simulation.h"

int main()
{
	srand(unsigned int (time(NULL)));
	Simulation simulation;
	simulation.run();
	
	return 0;
}