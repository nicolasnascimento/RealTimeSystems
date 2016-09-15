#ifndef POLLING_SERVER_H
#define POLLING_SERVER_H

typedef struct PollingServer {
	int identifier;
	int computingTime;
	int periodTime;
	int deadlineTime;
	int isComplete;
} PollingServer;

// Create a polling server fomr STDIN
PollingServer createPollingServerFromSTDIN();

// Prints the polling server to STDOUT
void printPollingServer(PollingServer pollingServer);


#endif

