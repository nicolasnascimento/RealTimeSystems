#include <stdio.h>

#include "Simulator.h"
#include "AperiodicTask.h"
#include "PeriodicTask.h" 


Simulator createSimulatorFromSTDIN() {
	Simulator simulator;
	scanf("%d", &simulator.simulationTime);
	scanf("%d", &simulator.amountOfPeriodicTasks);
	scanf("%d", &simulator.amountOfAperiodicTasks);
	for( int i = 0; i < simulator.amountOfPeriodicTasks; i++ ) {
		simulator.periodicTasks[i] = createPeriodicTaskFromSTDIN();	
	}
	for( int i = 0; i < simulator.amountOfAperiodicTasks; i++ ) {
		simulator.aperiodicTasks[i] = createAperiodicTaskFromSTDIN();
	}
	
	return simulator;
}

