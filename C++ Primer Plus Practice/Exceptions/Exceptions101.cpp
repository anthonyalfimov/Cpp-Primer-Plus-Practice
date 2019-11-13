//
//  Exceptions101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 13/11/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>

namespace
{
    double harmonicMean (double, double);
}

void showExceptions101()
{
    double x, y ,z;
    
    std::cout << "Enter two numbers: ";
    
    while (std::cin >> x >> y)
    {
        try                                 // begin try block
        {
            z = harmonicMean (x, y);
        }                                   // end try block
        catch (const char* errorString)     // begin exception handler
        {
            std::cout << errorString << "\n";
            std::cout << "Enter a new pair of numbers: ";
            continue;                       // skip to the beginning of the next iteration
        }                                   // end exception handler
        
        std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << "\n";
        std::cout << "Enter next set of numbers <q to quit>: ";
    }
    
    std::cout << "\nDone.\n";
}

namespace
{
    double harmonicMean (double a, double b)
    {
        if (a == -b)
            throw "bad harmonicMean() arguments: a = -b not allowed";
        
        return 2.0 * a * b / (a + b);
    }
}
