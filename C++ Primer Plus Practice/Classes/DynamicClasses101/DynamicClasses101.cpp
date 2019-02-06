//
//  DynamicClasses01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "StringBad01.hpp"

using namespace DynamicClasses101;

namespace
{
    void callme1(StringBad&);       // pass by reference
    void callme2(StringBad);        // pass by value
}

void showDynamicClasses101()
{
    {
        std::cout << "Starting inner block.\n";
        
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bowl for Dollars");
        
        std::cout << "\nheadline1: " << headline1 << "\n";
        std::cout << "headline2: " << headline2 << "\n";
        std::cout << "sports: "    << sports << "\n";
        
        callme1(headline1);
        std::cout << "headline1: " << headline1 << "\n";
        
        callme2(headline2);
        std::cout << "headline2: " << headline2 << "\n";
        
        std::cout << "\nInitialise one object to another:\n";
        StringBad sailor = sports;
        std::cout << "sailor: " << sailor << "\n";
        
        std::cout << "\nAssign one object to another:\n";
        StringBad knot;
        knot = headline1;
        std::cout << "knot: " << knot << "\n";
        
        std::cout << "Exiting inner block.\n\n";
    }
    std::cout << "\nDone.\n";
}

namespace
{
    void callme1(StringBad& s)
    {
        std::cout << "\nString passed by reference:\n";
        std::cout << "\t\"" << s << "\"\n";
    }
    
    void callme2(StringBad s)
    {
        std::cout << "\nString passed by value:\n";
        std::cout << "\t\"" << s << "\"\n";
    }
}
