//
//  AperiodicTask.hpp
//  T1
//
//  Created by Nicolas Nascimento on 23/09/16.
//  Copyright © 2016 NicolasNascimento. All rights reserved.
//

#ifndef AperiodicTask_hpp
#define AperiodicTask_hpp

#include <iostream>
#include "Task.hpp"

class AperiodicTask: public Task {
    // The arrival time for the task
    unsigned arrivalTime;
public:
    // Initialization
    AperiodicTask();
    AperiodicTask(const unsigned computingTime,const char identifier, const unsigned arrivalTime);
    // Destruction
    ~AperiodicTask();
    // Virtual Methods Implementation
    void executeWithCurrentTime(const unsigned& currentTime);
    void updateWithCurrentTime(const unsigned& currentTime);
    // Overriden Methods
    bool hasComputingLeftWithCurrentTime(const unsigned& currentTime) const;
};

#endif /* AperiodicTask_hpp */
