#ifndef APERIODICTASK_H
#define APERIODICTASK_H

typedef struct AperiodicTask {
	int identifier;
	int computingTime;
	int arrivalTime;
	int isComplete;
} AperiodicTask;


// Returns a new Aperiodic Task from STDIN
AperiodicTask createAperiodicTaskFromSTDIN();

// Prints the task to STDOUT
void printAperiodicTask(AperiodicTask task);

#endif /// APERIODICTASK_H


