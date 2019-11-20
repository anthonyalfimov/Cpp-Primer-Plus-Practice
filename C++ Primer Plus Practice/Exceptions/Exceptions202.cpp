//
//  Exceptions202.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 20/11/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include "Exceptions200.hpp"

namespace
{
    using namespace Exceptions200;
    
    double getHarmonicMean(double, double);
    double getGeometricMean(double, double);
    double getArithmeticMeanOfMeans(double, double);
    
    class Verbose
    {
    public:
        Verbose (const std::string& label) : mLabel (label)
        {
            std::cout << "> Verbose " << mLabel << " created\n";
        }
        ~Verbose()
        {
            std::cout << "> Verbose " << mLabel << " destroyed\n";
        }
        
        void show() const
        {
            std::cout << "> Verbose " << mLabel << " lives!\n";
        }
        
    private:
        std::string mLabel;
    };
}

void showExceptions202()
{
    double x, y, z;
    
    {
        Verbose dummy1 ("found in block in main()");
        std::cout << "\nEnter two numbers: ";
        
        while (std::cin >> x >> y)
        {
            try
            {
                z = getArithmeticMeanOfMeans (x, y);
                std::cout << "The arithmetic mean of arithmetic, geometric and harmonic means of "
                          << x << " and " << y << " is " << z << "\n";
                std::cout << "\nEnter the next pair: ";
            }
            catch (BadHarmonicMean& bhm)
            {
                bhm.message();
                std::cout << "\nTry again: ";
                continue;
            }
            catch (BadGeometricMean& bgm)
            {
                std::cout << bgm.message();
                std::cout << "> values used: " << bgm.arg1 << ", " << bgm.arg2 << "\n";
                std::cout << "\nSorry, you don't get to play any more.\n";
                break;
            }
        }
        
        dummy1.show();
    }
    
    std::cout << "\nDone.\n";
}

namespace
{
    double getHarmonicMean (double a, double b)
    {
        if (a == -b)
            throw BadHarmonicMean (a, b);
        
        return 2.0 * a * b / (a + b);
    }
    
    double getGeometricMean (double a, double b)
    {
        if (a < 0 || b < 0)
            throw BadGeometricMean (a, b);
        
        return std::sqrt (a * b);
    }
    
    double getArithmeticMeanOfMeans (double a, double b)
    {
        Verbose dummy2 ("found in getArithmeticMeanOfMeans()");
        
        double arithmeticMean, harmonicMean, geometricMean;
        
        arithmeticMean = (a + b) / 2.0;
        
        try
        {
            harmonicMean = getHarmonicMean(a, b);
            geometricMean = getGeometricMean(a, b);
        }
        catch (BadHarmonicMean& bhm)
        {
            bhm.message();
            std::cout << "> caught in getArithmeticMeanOfMeans()\n";
            throw;                      // rethrows the same exception
        }
        
        dummy2.show();
        
        return (arithmeticMean + harmonicMean + geometricMean) / 3.0;
    }
}
