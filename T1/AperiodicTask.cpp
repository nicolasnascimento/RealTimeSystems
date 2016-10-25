//
//  AperiodicTask.cpp
//  T1
//
//  Created by Nicolas Nascimento on 23/09/16.
//  Copyright © 2016 NicolasNascimento. All rights reserved.
//

#include "AperiodicTask.hpp"

using std::cout;


AperiodicTask::AperiodicTask():AperiodicTask(0, ' ', 0) {
    
}

AperiodicTask::AperiodicTask(const unsigned computingTime,const char identifier, const unsigned arrivalTime): Task(computingTime, identifier) {
    this->arrivalTime = arrivalTime;
}
// Destruction
AperiodicTask::~AperiodicTask() {
    
}
// Virtual Methods Implementation
void AperiodicTask::updateWithCurrentTime(const unsigned& currentTime) {
    
}

void AperiodicTask::executeWithCurrentTime(const unsigned& currentTime) {
    Task::executeWithCurrentTime(currentTime);
}

bool AperiodicTask::hasComputingLeftWithCurrentTime(const unsigned& currentTime) const {
    return Task::hasComputingLeftWithCurrentTime(currentTime) && currentTime >= this->arrivalTime;
}
