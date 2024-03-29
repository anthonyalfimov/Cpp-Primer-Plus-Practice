//
//  SpecialMethods101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  This short program demonstrate how a typecast-defining constuctor
//      and an assginment operator overload for a different type can
//      be used together
//

#include <iostream>
#include "MagicNumber01.hpp"

namespace
{
    // Use const to avoid modification of the temporary object that is returned
    const SpecialMethods101::MagicNumber returnConstructor(int);
    const SpecialMethods101::MagicNumber returnTempObject(int);
    
    // Function that returns a copy of a passed object
    SpecialMethods101::MagicNumber returnCopy(const SpecialMethods101::MagicNumber&);
}

void showSpecialMethods101()
{
    using SpecialMethods101::MagicNumber;
    
    // Constructor is called
    std::cout << "1: ";
    MagicNumber bar(3);
    
    // Constructor is called. Compiler optimises out the call to the copy constructor
    std::cout << "2: ";
    MagicNumber foo = 5;
    
    // If the assignment operator wasn't overloaded, the constructor would be
    //     used instead to convert `7` to a temoporary `MagicNumber` object that
    //     then would be assigned to `foo` using the implicit assignment operator
    std::cout << "3: ";
    foo = 7;
    
    // Call a function that returns an object by using a constructor call in the
    //     return statement. Constructor is called to create a temporary object;
    //     compiler optimises out the call to the copy constructor that would copy the temporary
    //     object into the return location
    std::cout << "4: ";
    returnConstructor(11);
    
    // Call a function that returns an object by using a local object in the
    //     return statement. Constructor is called to create the local object;
    //     compiler optimises out the call to the copy constructor that would copy this local
    //     object into the return location
    std::cout << "5: ";
    returnTempObject(43);
    
    // Call a function that returns a copy of a passed object and uses the copy constructor
    std::cout << "6: ";
    bar = returnCopy(foo);
    
    // Assign a return value to an object
    std::cout << "7: ";
    foo = returnConstructor(412);
    std::cout << "8: ";
    bar = returnTempObject(12);
    
    std::cout << "\n9: Dynamically allocate a Magic Number..\n";
    MagicNumber* dyn = new MagicNumber(111111);
    *dyn = 101010;
    // NOTE: the destructor for dynamically allocated object is ONLY called when
    //     you explicitely use delete
    //delete dyn;
    std::cout << "\n";
}

namespace
{
    const SpecialMethods101::MagicNumber returnConstructor(int i)
    {
        return SpecialMethods101::MagicNumber(i);       // Use constructor in the return statement
    }
    
    const SpecialMethods101::MagicNumber returnTempObject(int i)
    {
        // Even this gets optimised by the compiler!!!
        SpecialMethods101::MagicNumber tmp(i);          // Create temporary object
        return tmp;                                     // Return temporary object
    }
    
    SpecialMethods101::MagicNumber returnCopy(const SpecialMethods101::MagicNumber& mn)
    {
        return mn;
    }
}
