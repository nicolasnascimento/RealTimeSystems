//
//  Simulator.hpp
//  T1
//
//  Created by Nicolas Nascimento on 24/09/16.
//  Copyright © 2016 NicolasNascimento. All rights reserved.
//

#ifndef Simulator_hpp
#define Simulator_hpp

#include <iostream>
#include <vector>

#include "PeriodicTask.hpp"
#include "AperiodicTask.hpp"
#include "PollingServer.hpp"

class Simulator {
    // All tasks possible for the simulator
    vector<PeriodicTask> periodicTasks;
    vector<AperiodicTask> aperiodicTasks;
    // The polling server task
    PollingServer pollingServer;
    // This index will be used to determine the index for the polling server
    unsigned pollingServerIndex;
    // The idle process
    AperiodicTask idleProcess;
    
    // Iteration Varaiables
    unsigned simulationTime;
    unsigned currentTime;
    unsigned preemptions;
    unsigned contextSwitches;
    // This could be
    Task* currentTask;
    
protected:
    void executeNextTask();
    // Give a chance to all tasks to update
    void updateTasks();
    // Gets next task from the task queue
    Task* nextTaskToExecute();
    // Evaluates simualtion and exeucutes next task
    void stepSimulation();
public:
    // Initialization - from STDIN
    Simulator();
    // Destruction
    ~Simulator();
    // Begin simulation
    void beginExecution();
    // True the simulator is capable of performing execution
    bool canBeginExecution();
};

#endif /* Simulator_hpp */
