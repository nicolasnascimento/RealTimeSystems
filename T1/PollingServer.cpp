//
//  PollingServer.cpp
//  T1
//
//  Created by Nicolas Nascimento on 23/09/16.
//  Copyright © 2016 NicolasNascimento. All rights reserved.
//

#include "PollingServer.hpp"

PollingServer::PollingServer(const unsigned computingTime, const unsigned periodTime, const unsigned deadlineTime): PeriodicTask(computingTime, ' ', periodTime, deadlineTime) {
    this->identifier = "";
    this->tasks = vector<AperiodicTask*>();
}

PollingServer::PollingServer(): PollingServer(0, 0, 0) {

}

PollingServer::~PollingServer() {
    this->tasks.clear();
}

void PollingServer::executeWithCurrentTime(const unsigned& currentTime) {
    PeriodicTask::executeWithCurrentTime(currentTime);
    AperiodicTask* task = this->getAperiodicTaskToExecuteWithCurrentTime(currentTime);
    task->executeWithCurrentTime(currentTime);
}

void PollingServer::appendAperiodicTask(AperiodicTask* task) {
    
    this->tasks.push_back(task);
}

bool PollingServer::hasComputingLeftWithCurrentTime(const unsigned& currentTime) const {
    
    // No Aperiodic tasks, so no need for computing
    if( this->tasks.empty() ) {
        return false;
    // Check if the periodic task for the polling server still has any computing left
    }else if( PeriodicTask::hasComputingLeftWithCurrentTime(currentTime) ){
        // Check if any AperiodicTask wants to compute
        if( this->hasAnyAperiodicTaskWithComputingTimeLeft(currentTime) ) {
            return true;
        }
    }
    return false;
}

bool PollingServer::hasTask(Task *task) {
    for( int i = 0; i < this->tasks.size(); i++ ) {
        if( this->tasks[i]->getIdentifier() == task->getIdentifier() ) {
            return true;
        }
    }
    return false;
}

bool PollingServer::hasAnyAperiodicTaskWithComputingTimeLeft(const unsigned& currentTime) const {
    for( auto &&task : this->tasks ) {
        if( task->hasComputingLeftWithCurrentTime(currentTime) ) {
            return true;
        }
    }
    return false;
}

AperiodicTask* PollingServer::getAperiodicTaskToExecuteWithCurrentTime(const unsigned& currentTime) const {
    
    for( int i = 0; i < this->tasks.size(); i++ ) {
        if( this->tasks[i]->hasComputingLeftWithCurrentTime(currentTime) ) {
            return this->tasks[i];
        }
    }
    return NULL;
}
