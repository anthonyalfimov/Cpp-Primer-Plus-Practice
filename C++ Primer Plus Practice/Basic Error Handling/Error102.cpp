//
//  Error102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 08/11/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cfloat>

namespace
{
    bool harmonicMean (double a, double b, double* result);
}

void showError102()
{
    double x, y, z;
    
    std::cout << "Enter two numbers: ";
    
    while (std::cin >> x >> y)
    {
        if (harmonicMean (x, y, &z))
            std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << "\n";
        else
            std::cout << "One value should not be the negative of the other - try again!\n";
        
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
    
    std::cout << "\nDone.\n";
}

namespace
{
    bool harmonicMean (double a, double b, double* result)
    {
        if (a == -b)
        {
            *result = DBL_MAX;
            return false;
        }
        else
        {
            *result = 2.0 * a * b / (a + b);
            return true;
        }
    }
}

