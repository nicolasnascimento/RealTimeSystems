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
#include "PollingServer.h"

typedef struct Simulator{
	// Simulation Parameters
	int simulationTime;
	int amountOfAperiodicTasks;
	int amountOfPeriodicTasks;
	// The Polling Server Task
	PollingServer pollingServer;
	// All Aperiodic tasks
	AperiodicTask aperiodicTasks[MAXIMUM_APERIODIC_TASKS];
	// All periodic tasks
	PeriodicTask periodicTasks[MAXIMUM_PERIODIC_TASKS];
	
	
} Simulator;

// Initializes a Simulator from STDIN
Simulator createSimulatorFromSTDIN();

// Begins Simulation for Current Set of Tasks
void beginSimulation(Simulator* simulator);

// Determines next task to be run
void stepSimulation(Simulator* simulator, int step);


#endif // SIMULATOR_H
