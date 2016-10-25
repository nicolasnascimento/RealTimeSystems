//
//  Task.cpp
//  T1
//
//  Created by Nicolas Nascimento on 23/09/16.
//  Copyright © 2016 NicolasNascimento. All rights reserved.
//

#include "Task.hpp"

using std::cout;

// Initialization
Task::Task(const unsigned computingTime,const char identifier) {
    this->computingTime = computingTime;
    this->identifier = identifier;
    
    // This will be the same when creating a task
    this->computingLeft = computingTime;
}

Task::~Task() {
    
}

string Task::getIdentifier() {
    return this->identifier;
}

void Task::executeWithCurrentTime(const unsigned& currentTime) {
    cout << this->identifier;
    this->computingLeft--;
}

bool Task::hasComputingLeftWithCurrentTime(const unsigned& currentTime) const {
    return this->computingLeft != 0;
}
