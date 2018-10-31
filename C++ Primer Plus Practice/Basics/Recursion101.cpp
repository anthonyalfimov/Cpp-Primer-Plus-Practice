//
//  Recursion101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/10/2018.
//
//  Recursion with Single Recursive call
//

#include <iostream>

void countdown(int);    // recursive function prototype

void showRecursion101()
{
    countdown(4);
}

void countdown(int n)   // each recursive call allocates its own variables!
{
    std::cout << "Counting down ... " << n << "\t\t(n at " << &n << ")\n";
                        // executed on the way into recursion
    if (n > 0)
        countdown(n - 1);
    std::cout << n << ": Kaboom!\t\t\t\t(n at " << &n << ")\n";
                        // executed on the way out of recursion
}
