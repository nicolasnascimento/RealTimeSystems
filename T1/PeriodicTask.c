#include <stdio.h>

#include "PeriodicTask.h"

PeriodicTask createPeriodicTaskFromSTDIN() {
	PeriodicTask task;
	scanf("%d", &task.computingTime);
	scanf("%d", &task.periodTime);
	scanf("%d", &task.deadlineTime);
	task.identifier = 0;
	task.isComplete = 0;
	return task;
}


void printPeriodicTask(PeriodicTask task) {
	printf("Periodic Task %d [\n", task.identifier);
	printf("\tcomputingTime = %d\n", task.computingTime);
	printf("\tperiodTime = %d\n", task.periodTime);
	printf("\tdeadlineTime = %d\n", task.deadlineTime);
	printf("\tisComplete = %s\n",task.isComplete == 0 ? "NO" : "YES");
	printf("]");
}

void runPeriodicTask(PeriodicTask* task, char* operationOutput) {
	// Simply prints the identifier
	char character = task->identifier + 0x41;
	sprintf(operationOutput,"%c", character);
	printf("%c", character);
	//task->isComplete = 1;
}
