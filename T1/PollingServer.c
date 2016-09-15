
#include <stdio.h>

#include "PollingServer.h"

PollingServer createPollingServerFromSTDIN() {
	PollingServer pollingServer;
	scanf("%d", &pollingServer.computingTime);
	scanf("%d", &pollingServer.periodTime);
	scanf("%d", &pollingServer.deadlineTime);
	pollingServer.identifier = 0;
	pollingServer.isComplete = 0;

	return pollingServer;
}

void printPollingServer(PollingServer pollingServer) {
	printf("Polling Server %d[\n", pollingServer.identifier);
	printf("\tcomputingTime = %d\n", pollingServer.computingTime);
	printf("\tperiodTime = %d\n", pollingServer.periodTime);
	printf("\tdeadlineTime = %d\n", pollingServer.deadlineTime);
	printf("\tisComplete = %s\n", pollingServer.isComplete == 0 ? "NO" : "YES");
	printf("]\n");
}
