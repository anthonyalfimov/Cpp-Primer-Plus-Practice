//
//  StringBad.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Flawed (underdeveloped) string class
//

#ifndef StringBad01_hpp
#define StringBad01_hpp

#define VERBOSE_STRINGBAD_

#include <iostream>

namespace DynamicClasses101
{
    class StringBad
    {
    private:
        char* str;                  // pointer to string
        int length;                  // length of string
        static int strCount;        // number of objects
        
    public:
        StringBad(const char* s);   // constructor
        StringBad();                // default constructor
        ~StringBad();               // destructor
        
//      I/O Operator overloads
        friend std::ostream& operator<<(std::ostream& os, const StringBad& st);
    };
}   // end namespace DynamicClasses101

#endif /* StringBad_hpp */
