//
//  StringGood01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Fixed version of StringBad01
//

#include <cstring>
#include "StringGood01.hpp"

namespace DynamicClasses102
{
    // Initialise static class member
    int StringGood::strCount = 0;
    
    // Class methods
    StringGood::StringGood(const char* s)               // Construct from a C-string
    {
        length = static_cast<int>(std::strlen(s));      // set string size
        str = new char[length + 1];                     // allot storage
        std::strcpy(str, s);                            // initialise allocated storage
        strCount++;                                     // update object count
        
    #ifdef VERBOSE_STRINGGOOD_
        std::cout << strCount << ": \"" << str << "\" object created\n";
    #endif
    }
    
    StringGood::StringGood()                            // Default constructor
    {
        length = 4;
        str = new char[4];
        std::strcpy(str, "C++");                        // default string
        strCount++;
        
    #ifdef VERBOSE_STRINGGOOD_
        std::cout << strCount << ": \"" << str << "\" default object created\n";
    #endif
    }
    
    StringGood::StringGood(const StringGood& s)         // Explicit copy constructor
    {
        length = s.length;                              // same length
        str = new char[length + 1];                     // allot space
        std::strcpy(str, s.str);                        // copy string to new location
        strCount++;                                     // update object count
        
    #ifdef VERBOSE_STRINGGOOD_
        std::cout << strCount << ": \"" << str << "\" object copied\n";
    #endif
    }
    
    StringGood::~StringGood()                           // Necessary destructor
    {
    #ifdef VERBOSE_STRINGGOOD_
        std::cout << "\"" << str << "\" object being deleted, "
        << strCount - 1 << " strings left... ";
    #endif
        
        strCount--;                                     // required
        delete [] str;                                  // required
        
    #ifdef VERBOSE_STRINGGOOD_
        std::cout << "Done.\n";
    #endif
    }
    
    std::ostream& operator<<(std::ostream& os, const StringGood& s)
    {
        os << s.str;
        return os;
    }
}   // end namespace DynamicClasses102
