//
//  StringGood01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Fixed version of StringBad01
//

#ifndef StringGood01_hpp
#define StringGood01_hpp

#define VERBOSE_STRINGGOOD_

#include <iostream>

namespace DynamicClasses102
{
    class StringGood
    {
    private:
        char* str;                      // pointer to string
        int length;                     // length of string
        static int strCount;            // number of objects
        
    public:
        StringGood(const char* s);      // constructor
        StringGood();                   // default constructor
        StringGood(const StringGood&);  // explicit copy constructor
        ~StringGood();                  // destructor
        
//      Assignment Operator overload
        StringGood& operator=(const StringGood&);       // has to be a member function
        
//      I/O Operator overloads
        friend std::ostream& operator<<(std::ostream& os, const StringGood& st);
    };
}   // end namespace DynamicClasses102

#endif /* StringGood01_hpp */
