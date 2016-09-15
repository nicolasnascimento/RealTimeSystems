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

// Prints the task to STDOUT verbosily
void printAperiodicTask(AperiodicTask task);

// Executes the provided task and returns its output
void runAperiodicTask(AperiodicTask* task, char* operationOutput);

#endif /// APERIODICTASK_H


