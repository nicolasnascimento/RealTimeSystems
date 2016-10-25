//
//  PeriodicTask.cpp
//  T1
//
//  Created by Nicolas Nascimento on 23/09/16.
//  Copyright © 2016 NicolasNascimento. All rights reserved.
//

#include <iostream>
#include "PeriodicTask.hpp"

using std::cout;


PeriodicTask::PeriodicTask(const unsigned computingTime, const char identifier, const unsigned periodTime, const unsigned deadlineTime):Task(computingTime, identifier) {
    this->periodTime = periodTime;
    this->deadlineTime = deadlineTime;
}


PeriodicTask::~PeriodicTask() {
    
}

bool PeriodicTask::operator<(const PeriodicTask& task) const {
	return this->periodTime < task.getPeriodTime();
}

void PeriodicTask::updateWithCurrentTime(const unsigned& currentTime) {
    if( currentTime % this->periodTime == 0 ) {
        this->computingLeft = this->computingTime;
    }
}

unsigned PeriodicTask::getPeriodTime() const {
    return this->periodTime;
}

void PeriodicTask::executeWithCurrentTime(const unsigned& currentTime) {
    Task::executeWithCurrentTime(currentTime);
}

bool PeriodicTask::hasComputingLeftWithCurrentTime(const unsigned& currentTime) const {
    return Task::hasComputingLeftWithCurrentTime(currentTime);
}
