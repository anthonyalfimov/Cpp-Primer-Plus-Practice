//
//  TypeCasts101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 17/07/2018.
//

#include <iostream>

void showTypeCasts101()
{
    int auks, bats, coots;
    
    // following statement adds the values as doubles,
    // then converts the result to int
    auks = 19.99 + 11.99;
    
    // these statements add values as ints
    bats = (int) 19.99 + (int) 11.99;   // old C syntax
    coots = int(19.99) + int(11.99);    // C++ funtion-like syntax
    std::cout << "auks = " << auks << ", bats = " << bats
              << ", coots = " << coots << "\n";
    
    char ch {'Z'};
    std::cout << "The code for " << ch << " is " << int(ch) << "\n"
              << "Yes, the code is " << static_cast<int>(ch) << "\n";
}
