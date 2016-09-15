#include <stdlib.h>
#include <stdio.h>

#include "Simulator.h"
#include "AperiodicTask.h"
#include "PeriodicTask.h" 
#include "PollingServer.h"


Simulator createSimulatorFromSTDIN() {
	Simulator simulator;
	// Simulator Parameters
	scanf("%d", &simulator.simulationTime);
	scanf("%d", &simulator.amountOfPeriodicTasks);
	scanf("%d", &simulator.amountOfAperiodicTasks);
	
	if( simulator.simulationTime == 0 && simulator.amountOfPeriodicTasks == 0 && simulator.amountOfAperiodicTasks == 0 ){
		exit(EXIT_SUCCESS);
	}
		
	simulator.pollingServer = createPollingServerFromSTDIN();	
	for( int i = 0; i < simulator.amountOfPeriodicTasks; i++ ) {
		simulator.periodicTasks[i] = createPeriodicTaskFromSTDIN();	
	}
	for( int i = 0; i < simulator.amountOfAperiodicTasks; i++ ) {
		simulator.aperiodicTasks[i] = createAperiodicTaskFromSTDIN();
	}
	
	return simulator;
}

void beginSimulation(Simulator* simulator) {
	for( int i = 0; i < simulator->simulationTime; i++ ) {
		stepSimulation(simulator, i);
	}
}

void stepSimulation(Simulator* simulator, int step) {
	
}

