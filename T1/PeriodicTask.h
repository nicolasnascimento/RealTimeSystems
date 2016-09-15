#ifndef PERIODICTASK_H
#define PERIODICTASK_H

typedef struct PeriodicTask {
	int identifier;
	int computingTime;
	int periodTime;
	int deadlineTime;
	int isComplete;
} PeriodicTask;


// Returns a new Periodic Task created from STDIN
PeriodicTask createPeriodicTaskFromSTDIN();

// Prints the task to STDOUT verbosily
void printPeriodicTask(PeriodicTask task);

// Executes a PeriodicTask and returns its output
void runPeriodTask(PeriodicTask* task, char* operationOutput);

#endif // PERIODICTASK_H
