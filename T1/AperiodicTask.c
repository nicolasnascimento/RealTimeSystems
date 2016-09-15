#include <stdio.h>
#include <stdlib.h>

#include "AperiodicTask.h"


AperiodicTask createAperiodicTaskFromSTDIN() {
	AperiodicTask task;
	scanf("%d", &task.computingTime);
	scanf("%d", &task.arrivalTime);
	task.identifier = 0;
	task.isComplete = 0;
	return task;
}

void printAperiodicTask(AperiodicTask task) {
	printf("Aperiodic Task %d\n [", task.identifier);
	printf("\tcomputingTime = %d\n", task.computingTime);
	printf("\tarrivalTime = %d\n", task.arrivalTime);
	printf("\tisComplete = %s\n", task.isComplete == 0 ? "NO" : "YES");
	printf("]\n");	
}

void runAperiodicTask(AperiodicTask* task, char* operationOutput) {
	char character = task->identifier + 0x41;	
	sprintf(operationOutput, "%c", character);
	printf("%c", character);
	//task->isComplete = 1;
}
