//
//  StringType01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 14/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef StringType01_hpp
#define StringType01_hpp

#include <iostream>

namespace DynamicClasses201
{
    class String
    {
    private:
        char* m_str;                    // pointer to string
        int m_length;                   // length of string
        static int s_strCount;          // number of objects
        static const int CINLIM = 80;   // cin input limit
        
    public:
//      Constructors
        String(const char*);            // constructor
        String();                       // default constructor
        String(const String&);          // explicit copy constructor
        ~String();                      // destructor
        
//      Methods
        int length() const { return m_length; }
        
//      Assignment operator overloads
        String& operator=(const String&);   // has to be a member function
        String& operator=(const char*);     // speed up assigning string by avoiding tmp objects
        
//      Element access overloads
        char& operator[](int);              // has to be a member function
        const char& operator[](int) const;  // read-only version for const objects
        
//      Comparison operator overloads
        friend bool operator<(const String& st1, const String& st2);
        friend bool operator>(const String& st1, const String& st2);
        friend bool operator==(const String& st1, const String& st2);
        
//      I/O operator overloads
        friend std::ostream& operator<<(std::ostream& os, const String& st);
        friend std::istream& operator>>(std::istream& is, String& st);      // basic implementation
        
//      Static methods
        static int stringCount();
    };
}   // end namespace DynamicClasses201

#endif /* StringType01_hpp */
