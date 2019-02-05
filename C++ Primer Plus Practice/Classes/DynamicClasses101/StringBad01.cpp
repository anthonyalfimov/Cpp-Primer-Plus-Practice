//
//  StringBad.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Flawed (underdeveloped) string class
//

#include <cstring>
#include "StringBad01.hpp"

namespace DynamicClasses101
{
    // Initialise static class member
    int StringBad::strCount = 0;
    
    // Class methods
    StringBad::StringBad(const char* s)                 // Construct from a C-string
    {
        length = static_cast<int>(std::strlen(s));      // set string size
        str = new char[length + 1];                     // allot storage
        std::strcpy(str, s);                            // initialise allocated storage
        strCount++;                                     // update object count
        
    #ifdef VERBOSE_STRINGBAD_
        std::cout << strCount << ": \"" << str << "\" object created\n";
    #endif
    }
    
    StringBad::StringBad()                              // Default constructor
    {
        length = 4;
        str = new char[4];
        std::strcpy(str, "C++");                        // default string
        strCount++;
        
    #ifdef VERBOSE_STRINGBAD_
        std::cout << strCount << ": \"" << str << "\" default object created\n";
    #endif
    }
    
    StringBad::~StringBad()                             // Necessary destructor
    {
    #ifdef VERBOSE_STRINGBAD_
        std::cout << "\"" << str << "\" object deleted, "
                  << strCount - 1 << " strings left\n";
    #endif
        
        strCount--;                                     // required
        delete [] str;                                  // required
    }
    
    std::ostream& operator<<(std::ostream& os, const StringBad& s)
    {
        os << s.str;
        return os;
    }
}
