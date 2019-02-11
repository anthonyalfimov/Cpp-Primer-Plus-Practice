//
//  DynamicClasses102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "StringGood01.hpp"

using namespace DynamicClasses102;

namespace
{
    void callme1(StringGood&);       // pass by reference
    void callme2(StringGood);        // pass by value
}

void showDynamicClasses102()
{
    {
        std::cout << "Starting inner block.\n";
        
        StringGood headline1("Celery Stalks at Midnight");
        StringGood headline2("Lettuce Prey");
        StringGood sports("Spinach Leaves Bowl for Dollars");
        
        std::cout << "\nheadline1: " << headline1 << "\n";
        std::cout << "headline2: " << headline2 << "\n";
        std::cout << "sports: "    << sports << "\n";
        
        callme1(headline1);
        std::cout << "headline1: " << headline1 << "\n";
        
        callme2(headline2);
        std::cout << "headline2: " << headline2 << "\n";
        
        std::cout << "\nInitialise one object to another:\n";
        StringGood sailor = sports;
        std::cout << "sailor: " << sailor << "\n";
        
        std::cout << "\nAssign one object to another:\n";
        StringGood knot;
        knot = headline1;
        std::cout << "knot: " << knot << "\n";
        
        std::cout << "Exiting inner block.\n\n";
    }
    std::cout << "\nDone.\n";
}

namespace
{
    void callme1(StringGood& s)
    {
        std::cout << "\nString passed by reference:\n";
        std::cout << "\t\"" << s << "\"\n";
    }
    
    void callme2(StringGood s)
    {
        std::cout << "\nString passed by value:\n";
        std::cout << "\t\"" << s << "\"\n";
    }
}

