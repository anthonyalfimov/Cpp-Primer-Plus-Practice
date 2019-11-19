//
//  Exceptions201.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 19/11/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "Exceptions201.hpp"

namespace Exceptions201
{
    double harmonicMean (double, double);
    double geometricMean (double, double);
}

void showExceptions201()
{
    using namespace Exceptions201;
    
    double x, y ,z;
    
    std::cout << "Enter two numbers: ";
    
    while (std::cin >> x >> y)
    {
        try
        {
            z = harmonicMean(x, y);
            std::cout << "Harmonic mean of " << x << " and " << y << " is " << z << "\n";
            
            z = geometricMean(x, y);
            std::cout << "Geometric mean of " << x << " and " << y << " is " << z << "\n";
            
            std::cout << "Enter next set of numbers <q to quit>: ";
        }
        catch (BadHarmonicMean& bhm)        // catch by reference to facilitate polymorphism
        {
            bhm.message();
            std::cout << "Try again <q to quit>: ";
            continue;                       // start next loop iteration
        }
        catch (BadGeometricMean& bgm)
        {
            std::cout << bgm.message();
            std::cout << "> values used: " << bgm.arg1 << ", " << bgm.arg2 << "\n";
            std::cout << "Sorry, you don't get to play anymore!\n";
            break;                          // terminate loop
        }
    }
    
    std::cout << "\nDone.\n";
}

namespace Exceptions201
{
    double harmonicMean (double a, double b)
    {
        if (a == -b)
            throw BadHarmonicMean (a, b);
        
        return 2.0 * a * b / (a + b);
    }
    
    double geometricMean (double a, double b)
    {
        if (a < 0 || b < 0)
            throw BadGeometricMean (a, b);
        
        return std::sqrt (a * b);
    }
}
