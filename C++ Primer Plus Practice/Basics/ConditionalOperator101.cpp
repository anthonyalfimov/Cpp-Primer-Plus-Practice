//
//  ConditionalOperator101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 18/09/2018.
//

#include <iostream>

void showConditionalOperator101()
{
    int a, b;
    std::cout << "Enter two integers: ";
    std::cin >> a >> b;
    std::cout << "The larger of " << a << " and " << b;
    
    int c {a > b ? a : b};
    
    std::cout << " is " << c << "\n";
}
