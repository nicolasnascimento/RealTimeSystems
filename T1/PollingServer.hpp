//
//  PollingServer.hpp
//  T1
//
//  Created by Nicolas Nascimento on 23/09/16.
//  Copyright © 2016 NicolasNascimento. All rights reserved.
//

#ifndef PollingServer_hpp
#define PollingServer_hpp

#include <vector>
#include "PeriodicTask.hpp"
#include "AperiodicTask.hpp"

using std::vector;

class PollingServer: public PeriodicTask {
    
protected:
    vector<AperiodicTask*> tasks;
    // Returns true if any AperiodicTask has computing time left in the give time
    bool hasAnyAperiodicTaskWithComputingTimeLeft(const unsigned& currentTime) const;
    AperiodicTask* getAperiodicTaskToExecuteWithCurrentTime(const unsigned& currentTime) const;
public:
    // Initialization
    PollingServer();
    PollingServer(const unsigned computingTime, const unsigned periodTime, const unsigned deadlineTime);
    // Destruction
    ~PollingServer();
    // Returns true if a task is within the task
    bool hasTask(Task* task);
    // Overriden Methods
    void executeWithCurrentTime(const unsigned& currentTime);
    // Adds append to the list of Aperiodic Tasks
    void appendAperiodicTask(AperiodicTask* task);
    // Follow the polling server rule
    bool hasComputingLeftWithCurrentTime(const unsigned& currentTime) const;
};

#endif /* PollingServer_hpp */
