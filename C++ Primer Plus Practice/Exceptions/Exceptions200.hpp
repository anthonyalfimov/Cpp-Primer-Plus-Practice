//
//  Exceptions201.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 19/11/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Exceptions200_hpp
#define Exceptions200_hpp

#include <iostream>

namespace Exceptions200
{
    class BadHarmonicMean
    {
    public:
        BadHarmonicMean (double a = 0, double b = 0, bool isVerbose = false)
            : mArg1 (a), mArg2 (b), mIsVerbose(isVerbose)
        {
            if (mIsVerbose)
                std::cout << "\n> Created BadHarmonicMean exception <\n\n";
        }
        ~BadHarmonicMean()
        {
            if (mIsVerbose)
                std::cout << "\n> Destroyed BadHarmonicMean exception <\n\n";
        }
        void message() const;
        
    private:
        double mArg1;
        double mArg2;
        bool   mIsVerbose;
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
        
        BadGeometricMean (double a = 0, double b = 0, bool isVerbose = false)
            : arg1 (a), arg2 (b), mIsVerbose(isVerbose)
        {
            if (mIsVerbose)
                std::cout << "\n> Created BadGeometricMean exception <\n\n";
        }
        ~BadGeometricMean()
        {
            if (mIsVerbose)
                std::cout << "\n> Destroyed BadGeometricMean exception <\n\n";
        }
        const char* message() const;        // ok because returns pointer to a const string
        
    private:
        bool mIsVerbose;
    };
    
    inline const char* BadGeometricMean::message() const
    {
        return "> geometricMean() arguments must be >= 0\n";
    }
}   // end namespace Exceptions200

#endif /* Exceptions200_hpp */
