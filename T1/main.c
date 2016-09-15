#include <stdio.h>
#include <stdlib.h>


#include "Simulator.h"

int main(int argc, const char* argv[]) {	
	
	while(1) {
		Simulator simulator = createSimulatorFromSTDIN();
		beginSimulation(&simulator);
	
	}
	
	exit(EXIT_SUCCESS);
}
