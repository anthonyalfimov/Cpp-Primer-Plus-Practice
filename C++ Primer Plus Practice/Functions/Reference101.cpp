//
//  Reference101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 12/10/2018.
//

#include <iostream>

namespace Reference101
{
    void swapRef(int & a, int & b);     // a, b are aliases for ints
    void swapPtr(int * p, int * q);     // p, q are addresses of ints
    void swapVal(int a, int b);         // a, b are copies of ints
}

using namespace Reference101;

void showReference101()
{
    int wallet1 {300};
    int wallet2 {350};
    
    std::cout << "wallet 1 = $" << wallet1
              << " wallet 2 = $" << wallet2 << "\n";
    
    std::cout << "Using references to swap contents:\n";
    swapRef(wallet1, wallet2);          // pass variables
    std::cout << "wallet 1 = $" << wallet1
              << " wallet 2 = $" << wallet2 << "\n";
    
    std::cout << "Using pointers to swap contents:\n";
    swapPtr(&wallet1, &wallet2);        // pass addresses of variables
    std::cout << "wallet 1 = $" << wallet1
              << " wallet 2 = $" << wallet2 << "\n";
    
    std::cout << "Trying to use passing by value:\n";
    swapVal(wallet1, wallet2);          // pass values of variables
    std::cout << "wallet 1 = $" << wallet1
              << " wallet 2 = $" << wallet2 << "\n";
}

void Reference101::swapRef(int & a, int & b)
{
    int temp {a};
    a = b;
    b = temp;
}

void Reference101::swapPtr(int * p, int * q)
{
    int temp {*p};
    *p = *q;
    *q = temp;
}

// quite a pointless function
void Reference101::swapVal(int a, int b)
{
    int temp {a};
    a = b;
    b = temp;
}
