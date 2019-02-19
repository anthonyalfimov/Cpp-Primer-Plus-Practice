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
        std::cout << "Assignement overload for int called\n";
        num = n;
        return *this;
    }
    
    // Assignment operator
    MagicNumber& MagicNumber::operator=(const MagicNumber& mn)
    {
        std::cout << "Assignement overload for MagicNumber called\n";
        num = mn.num;
        return *this;
    }
    
    // Copy constructor
    MagicNumber::MagicNumber(const MagicNumber& mn)
    {
        std::cout << "Copy constructor called\n";
        num = mn.num;
    }
    
    // Destructor
    MagicNumber::~MagicNumber()
    {
        std::cout << num << " says \"Bye!\"\n";
    }
    
}   // end namespace SpecialMethods101
