//
//  PointerArithmetic101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/08/2018.
//

#include <iostream>

void showPointerArithmetic101()
{
    double wages[3] {10000.0, 20000.0, 30000.0};
    short  stacks[3] {3, 2, 1};
        
    // Two ways to get an address of an array
    double * pw = wages;        // name of an array = address
    short * ps = &stacks[0];
    
    std::cout << "pw = " << pw << ", *pw = " << *pw << "\n";
    ++pw;
    std::cout << "Add 1 to the pw pointer:\n"
              << "pw = " << pw << ", *pw = " << *pw << "\n\n";
    
    std::cout << "ps = " << ps << ", *ps = " << *ps << "\n";
    ++ps;
    std::cout << "Add 1 to the ps pointer:\n"
              << "ps = " << ps << ", *ps = " << *ps << "\n\n";
    
    std::cout << "Access two elements with array notation\n"
              << "stacks[0] = " << stacks[0]
              << ", stacks[1] = " << stacks[1] << "\n"
              << "Access two elements with pointer notation\n"
              << "*stacks = " << *stacks
              << ", *(stacks + 1) = " << *(stacks + 1) << "\n";
    
    std::cout << sizeof(wages) << " = size of wages array\n"
              << sizeof(pw) << " = size of pw pointer\n";
}
