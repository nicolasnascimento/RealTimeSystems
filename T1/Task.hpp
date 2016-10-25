//
//  Task.hpp
//  T1
//
//  Created by Nicolas Nascimento on 23/09/16.
//  Copyright © 2016 NicolasNascimento. All rights reserved.
//

#ifndef Task_hpp
#define Task_hpp

#include <iostream>

using std::string;

class Task{
    
protected:
    // The amount of computing this particular task needs
    unsigned computingTime;
    // The amount of computing this particular task still needs
    int computingLeft;
    // The identifier for this particular task
    string identifier;
public:
    /// Initializers
    Task(const unsigned computingTime,const char identifier);
    // Destructors
    virtual ~Task() = 0;
    // Virtual Methods
    // Execution callbacks
    virtual void executeWithCurrentTime(const unsigned& currentTime) = 0;
    virtual void updateWithCurrentTime(const unsigned& currentTime) = 0;
    // Tells wheter the object need computing
    virtual bool hasComputingLeftWithCurrentTime(const unsigned& currentTime) const = 0;
    // Getters
    string getIdentifier();
    
};

#endif /* Task_hpp */
