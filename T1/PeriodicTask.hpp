//
//  PeriodicTask.hpp
//  T1
//
//  Created by Nicolas Nascimento on 23/09/16.
//  Copyright © 2016 NicolasNascimento. All rights reserved.
//

#ifndef PeriodicTask_hpp
#define PeriodicTask_hpp

#include <iostream>
#include "Task.hpp"


class PeriodicTask: public Task {
   
protected:
    // The period and deadline for the task
    unsigned periodTime;
    unsigned deadlineTime;
public:
    // Initialization
    PeriodicTask(const unsigned computingTime, const char identifier, const unsigned periodTime, const unsigned deadlineTime);
    // Destruction
    ~PeriodicTask();
    // Getters
    unsigned getPeriodTime() const;
    // Virtual methods are implemented
    void executeWithCurrentTime(const unsigned& currentTime);
    void updateWithCurrentTime(const unsigned& currentTime);
    bool hasComputingLeftWithCurrentTime(const unsigned& currentTime) const;
	
    // Comparasion
    bool operator<(const PeriodicTask& task) const;
};


#endif /* PeriodicTask_hpp */
