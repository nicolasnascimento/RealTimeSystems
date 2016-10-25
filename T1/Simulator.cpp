//
//  Simulator.cpp
//  T1
//
//  Created by Nicolas Nascimento on 24/09/16.
//  Copyright © 2016 NicolasNascimento. All rights reserved.
//

#include "Simulator.hpp"

#include <iostream>

using std::cin;
using std::vector;
using std::cout;
using std::endl;
using std::find;

Simulator::Simulator() {
    
    this->idleProcess = AperiodicTask(0, '.', 0);
    // Initial Allocation
    this->aperiodicTasks = vector<AperiodicTask>();
    this->periodicTasks = vector<PeriodicTask>();
    this->pollingServerIndex = 0;
    this->preemptions = 0;
    this->contextSwitches = 0;    

    // Safety
    this->currentTask = NULL;
    this->currentTime = 0;
    
    // Read default values from STDIN
    unsigned amountOfPeriodicTasks = 0;
    unsigned amountOfAperiodicTasks = 0;
    
    cin >> this->simulationTime;
    cin >> amountOfPeriodicTasks;
    cin >> amountOfAperiodicTasks;
    
    // Reserve to improve performance
    this->aperiodicTasks.reserve(amountOfAperiodicTasks);
    this->periodicTasks.reserve(amountOfPeriodicTasks);
    
    // General Purpose Variables for reading input
    unsigned periodTime = 0;
    unsigned deadlineTime = 0;
    unsigned computingTime = 0;
    unsigned arrivalTime = 0;
    
    // No point going any further if no simulation shall be performed
    if( this->simulationTime > 0 ) {
    
        // Polling Server
        cin >> computingTime;
        cin >> periodTime;
        cin >> deadlineTime;
        this->pollingServer = PollingServer(computingTime, periodTime, deadlineTime);
        
        // Periodic Tasks
        char identifier = 'A';
        for( int i = 0; i < amountOfPeriodicTasks; i++, identifier++ ) {
            cin >> computingTime;
            cin >> periodTime;
            cin >> deadlineTime;
            this->periodicTasks.push_back(PeriodicTask(computingTime, identifier, periodTime, deadlineTime));
        }

	sort(this->periodicTasks.begin(), this->periodicTasks.end());
	
	for( int i = 0; i < amountOfPeriodicTasks; i++ ) {
	    PeriodicTask* task = &this->periodicTasks[i];
	    if( task->getPeriodTime() < this->pollingServer.getPeriodTime() ) {
                this->pollingServerIndex++;
            }
        }
        
        // Aperiodic Tasks
        for( int i = 0; i < amountOfAperiodicTasks; i++, identifier++ ) {
            cin >> arrivalTime;
            cin >> computingTime;
            this->aperiodicTasks.push_back(AperiodicTask(computingTime, identifier, arrivalTime));
        }
        
    }	
    
}

Simulator::~Simulator() {
    // Empty Containers
    this->periodicTasks.clear();
    this->aperiodicTasks.clear();
    // Safety
    this->currentTask = NULL;
    this->currentTime = 0;
    this->pollingServerIndex = 0;
}

void Simulator::beginExecution() {
    for( this->currentTime = 0; this->currentTime < this->simulationTime; this->currentTime++ ) {
        
        this->stepSimulation();
    }
    cout << endl;
    cout << this->preemptions << " " << this->contextSwitches << endl;
}

void Simulator::stepSimulation() {
    
    this->updateTasks();

    this->executeNextTask();
    
}

Task* Simulator::nextTaskToExecute() {
    
    for( int i = 0; i < this->periodicTasks.size(); i++ ) {
        Task* task = &this->periodicTasks[i];
        // Give the polling server a chance to execute
        if( i == this->pollingServerIndex ) {
            if( (this->pollingServer.hasComputingLeftWithCurrentTime(this->currentTime) && this->currentTime % this->pollingServer.getPeriodTime() == 0) ||
               (this->pollingServer.hasComputingLeftWithCurrentTime(this->currentTime) && &this->pollingServer == this->currentTask)) {
                return &this->pollingServer;
            }
        }
        if( task->hasComputingLeftWithCurrentTime(this->currentTime) ) {
            return task;
        }
    }
    
    // Check if polling server wishes to process before returning and idle process
    if( this->pollingServer.hasComputingLeftWithCurrentTime(this->currentTime) ) {
        return &this->pollingServer;
    }

    return &this->idleProcess;
}

void Simulator::updateTasks() {
    // Polling server
    this->pollingServer.updateWithCurrentTime(this->currentTime);
    // Update periodic tasks
    //for( auto &&task : this->periodicTasks ) {
    for( int i = 0; i < this->periodicTasks.size(); i++ ) {
	Task* task = &this->periodicTasks[i];
	task->updateWithCurrentTime(this->currentTime);
    }
    // Update AperiodicTasks
    for( int i = 0; i < this->aperiodicTasks.size(); i++ ) {
        AperiodicTask* task = &this->aperiodicTasks[i];
        task->updateWithCurrentTime(this->currentTime);
        if( task->hasComputingLeftWithCurrentTime(this->currentTime) ) {
            this->pollingServer.appendAperiodicTask(task);
        }
    }
}

void Simulator::executeNextTask() {
    
    Task* nextTask = this->nextTaskToExecute();
    
    if( nextTask != NULL && nextTask != this->currentTask ) {
        
        // Only begin checking for preeemptions if first iteration is over
        if( this->currentTime != 0 ) {
            string currentTaskIdentifier = this->pollingServer.hasTask(this->currentTask) ? "P" : this->currentTask->getIdentifier();
            string nextTaskIdentifier =  this->pollingServer.hasTask(nextTask) ? "P" : nextTask->getIdentifier();
            if( this->currentTask->hasComputingLeftWithCurrentTime(this->currentTime) && nextTask != &this->idleProcess && currentTaskIdentifier != nextTaskIdentifier) {
                this->preemptions++;
            }
	    if( currentTaskIdentifier != nextTaskIdentifier ){
                this->contextSwitches++;
            }
        }
        
        this->currentTask = nextTask;
    }
    this->currentTask->executeWithCurrentTime(this->currentTime);
}

bool Simulator::canBeginExecution() {
    return this->simulationTime != 0 && !this->periodicTasks.empty() && !this->aperiodicTasks.empty();
}


