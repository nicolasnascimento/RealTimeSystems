//
//  main.cpp
//  T1
//
//  Created by Nicolas Nascimento on 23/09/16.
//  Copyright © 2016 NicolasNascimento. All rights reserved.
//

#include <iostream>
#include "Simulator.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Simulator* currentSimulator = new Simulator();
    
    while (currentSimulator->canBeginExecution()) {
        currentSimulator->beginExecution();
        
        delete currentSimulator;
        currentSimulator = new Simulator();
    }
    
    delete currentSimulator;
    
    return 0;
}
