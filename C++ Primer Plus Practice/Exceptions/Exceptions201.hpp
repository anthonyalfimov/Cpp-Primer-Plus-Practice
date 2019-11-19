//
//  Exceptions201.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 19/11/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Exceptions201_hpp
#define Exceptions201_hpp

#include <iostream>

namespace Exceptions201
{
    class BadHarmonicMean
    {
    public:
        BadHarmonicMean (double a = 0, double b = 0) : mArg1 (a), mArg2 (b) {}
        void message() const;
        
    private:
        double mArg1;
        double mArg2;
    };
    
    inline void BadHarmonicMean::message() const
    {
        std::cout << "> harmonicMean (" << mArg1 << ", " << mArg2 << ") - "
                  << "invalid arguments: a = -b\n";
    }
    
    class BadGeometricMean
    {
    public:
        double arg1;
        double arg2;
        
        BadGeometricMean (double a = 0, double b = 0) : arg1 (a), arg2 (b) {}
        const char* message() const;        // ok because returns pointer to a const string
    };
    
    inline const char* BadGeometricMean::message() const
    {
        return "> geometricMean() arguments must be >= 0\n";
    }
}   // end namespace Exceptions201

#endif /* Exceptions201_hpp */
