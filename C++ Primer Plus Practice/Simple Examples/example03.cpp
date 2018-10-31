//
//  example03.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 18/09/2018.
//

#include <iostream>
#include <climits>

bool isInt(double);

void showExample03()
{
    double num;
    
    std::cout << "Enter an integer value: ";
    std::cin >> num;
    while (!isInt(num))     // input validation loop
    {
        std::cout << "Out of bounds! Please try again: ";
        std::cin >> num;
    }
    int value = static_cast<int>(num);  // type cast
    std::cout << "You've entered the integer " << value << "\nGoodbye see you!\n";
}

bool isInt(double x)
{
    if (x <= INT_MAX and x >= INT_MIN)   // use climits values; note alternative to &&
        return true;
    else
        return false;
}
