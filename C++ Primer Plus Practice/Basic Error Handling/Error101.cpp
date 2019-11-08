//
//  Error101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 08/11/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstdlib>

namespace
{
    double harmonicMean (double, double);
}

void showError101()
{
    double x, y, z;
    
    std::cout << "Enter two numbers: ";
    
    while (std::cin >> x >> y)
    {
        z = harmonicMean (x, y);
        std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << "\n"
                  << "Enter next set of numbers <q to quit>: ";
    }
    
    std::cout << "\nDone.\n";
}

namespace
{
    double harmonicMean(double a, double b)
    {
        if (a == -b)
        {
            std::cout << "Untenable arguments to harmonicMean()\n";
            std::abort();
            //std::exit(EXIT_FAILURE);
        }
        
        return 2.0 * a * b / (a + b);
    }
}
