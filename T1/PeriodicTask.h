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

// Prints the task to STDOUT
void printPeriodicTask(PeriodicTask task);

#endif // PERIODICTASK_H
