//
//  InlineFunc101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 12/10/2018.
//

#include <iostream>

namespace InlineFunc101
{
//  Inline function definition:
    inline double square(double x) { return x * x; }
}

using namespace InlineFunc101;

void showInlineFunc101()
{
    double a, b;
    double c {13.0};
    
    a = square(5.0);
    b = square(4.5 + 7.5);  // can pass expressions
    
    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "c = " << c;
    std::cout << ", c squared = " << square(c++) << "\n";
    std::cout << "Now c = " << c << "\n";
    
    std::cout << "\n Done.\n";
}
