//
//  LocalStaticVars102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 08/11/2018.
//
//  Demonstrate (one-time) dynamic initialization of a local static variable
//

#include <iostream>
#include <cmath>

namespace LocalStaticVars102
{
//  Function prototype
    void messWithPi(double delta = 0);
}

void showLocalStaticVars102()
{
    using namespace LocalStaticVars102;
    messWithPi();
    messWithPi(2.0);
    messWithPi(-9.0);
    messWithPi();
}

void LocalStaticVars102::messWithPi(double delta)
{
    static double pi = 4.0 * atan(1.0);     // local static variable with dynamic initialization
    pi += delta;
    std::cout << "Today Pi = " << pi << "\n";
}
