//
//  SupportEV101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 08/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

extern double ev_warming;       // use warming from another file

//  Function prototypes
void ev_update(double dt);
void ev_local();

void ev_update(double dt)       // modifies global variable
{
    extern double ev_warming;   // optional redeclaration
    ev_warming += dt;
    std::cout << "Updated global warming to " << ev_warming << " degrees.\n";
}

void ev_local()                 // uses local variable
{
    double ev_warming {0.8};    // new variable hide external one
    std::cout << "Local warming is " << ev_warming << " degrees.\n";
    
//  Access global variable with the scope resolution operator:
    std::cout << "But global warming is " << ::ev_warming << " degrees.\n";
}
