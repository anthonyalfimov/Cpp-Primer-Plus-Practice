//
//  StaticInternalVars101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 08/11/2018.
//
//  Static duration variables with internal linkage
//

#include <iostream>

//  NOTE: Usually, we use namespaces to conceal variables and function prototypes.
//  In this case, however, the whole point is to look at how external variables
//  work without namespaces.
//  For this reason we use prefixes with function and variable names.

int siv_tom {3};            // external variable definition
int siv_dick {30};          // external variable definition
static int siv_harry {300}; // static, internal linkage

//  Function prototype
void siv_remoteAccess();

void showStaticInternalVars101()
{
    std::cout
        << "main() reports the following addresses:\n"
        << "&tom = " << &siv_tom
        << ", &dick = " << &siv_dick
        << ", &harry = " << &siv_harry << "\n";
    
    siv_remoteAccess();
}
