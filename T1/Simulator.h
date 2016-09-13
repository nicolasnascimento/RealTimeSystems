#ifndef SIMULATOR_H
#define SIMULATOR_H

#define MAXIMUM_SIMULATION_TIME 100000
#define MAXIMUM_PERIODIC_TASKS 13
#define MAXIMUM_APERIODIC_TASKS 13
#define MAXIMUM_COMPUTING_PERIOD 100000
#define MAXIMUM_EXECUTING_PERIOD 100000
#define MAXIMUM_DEADLINE_PERIOD 100000
#define MAXIMUM_ARRIVAL_PERIOD 100000

#include "PeriodicTask.h"
#include "AperiodicTask.h"

typedef struct Simulator{
	// Simulation Parameters
	int simulationTime;
	int amountOfAperiodicTasks;
	int amountOfPeriodicTasks;
	// The tasks
	AperiodicTask aperiodicTasks[MAXIMUM_APERIODIC_TASKS];
	PeriodicTask periodicTasks[MAXIMUM_PERIODIC_TASKS];
	
	
} Simulator;

Simulator createSimulatorFromSTDIN();

#endif // SIMULATOR_H
