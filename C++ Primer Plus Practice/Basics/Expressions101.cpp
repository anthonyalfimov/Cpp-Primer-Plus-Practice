//
//  Expressions101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 17/08/2018.
//

#include <iostream>

void showExpressions101()
{
    int x;
    
    // assignment is a C++ expression that has a value
    
    std::cout
        << "The expression x = 100 has the value "
        << (x = 100) << "\n";
    std::cout
        << "Now x = " << x << "\n"
        << "The expression x < 3 has the value "
        << (x < 3) << "\n"
        << "The expression x > 3 has the value "
        << (x > 3) << "\n";
    
    // display true or false for bool
    std::cout.setf(std::ios_base::boolalpha);
    
    std::cout
        << "The expression x < 3 has the value "
        << (x < 3) << "\n"
        << "The expression x > 3 has the value "
        << (x > 3) << "\n";
}
