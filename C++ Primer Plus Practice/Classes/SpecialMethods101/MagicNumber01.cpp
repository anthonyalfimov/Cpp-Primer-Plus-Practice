//
//  MagicNumber01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "MagicNumber01.hpp"

namespace SpecialMethods101
{
    // Use constructor to initialise object to type int
    MagicNumber::MagicNumber(int n)
    {
        std::cout << "Constructor called\n";
        num = n;
    }
    
    // Use assignment overload to assign object to type int
    MagicNumber& MagicNumber::operator=(int n)
    {
        std::cout << "Assignement overload called\n";
        num = n;
        return *this;
    }
}   // end namespace SpecialMethods101
