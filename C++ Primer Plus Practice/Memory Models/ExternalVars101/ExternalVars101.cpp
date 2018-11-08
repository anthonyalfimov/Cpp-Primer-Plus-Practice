//
//  ExternalVars101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 08/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

//  NOTE: Usually, we use namespaces to conceal variables and function prototypes.
//  In this case, however, the whole point is to look at how external variables
//  work without namespaces.
//  For this reason we use prefixes with function and variable names.

//  External variable
double ev_warming {0.3};       // `warming` definition

//  Function prototypes
void ev_update(double dt);
void ev_local();

void showExternalVars101()      // use external variable
{
    std::cout << "Global warming is " << ev_warming << " degrees.\n";
    ev_update(0.1);             // call function to change ev_warming
    std::cout << "Global warming is " << ev_warming << " degrees.\n";
    ev_local();                 // call function with local ev_warming
    std::cout << "Global warming is " << ev_warming << " degrees.\n";
}
