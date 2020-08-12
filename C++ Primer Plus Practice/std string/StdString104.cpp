//
//  StdString104.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 12/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// std::string capacity
//==================================================================================================

#include <iostream>
#include <string>

void showStdString104()
{
    std::string empty;
    std::string small ("bit");
    std::string large ("Elephants are a girl's best friend");
    
    std::cout
        << "Sizes:\n"
        << "\tempty: " << empty.size() << "\n"
        << "\tsmall: " << small.size() << "\n"
        << "\tlarge: " << large.size() << "\n"
        << "\nCapacities:\n"
        << "\tempty: " << empty.capacity() << "\n"
        << "\tsmall: " << small.capacity() << "\n"
        << "\tlarge: " << large.capacity() << "\n";
    
    empty.reserve(50);
    
    std::cout << "\nCapacity after empty.reserve(50): " << empty.capacity() << "\n";
    
    std::cout << "\nDone.\n";
}
