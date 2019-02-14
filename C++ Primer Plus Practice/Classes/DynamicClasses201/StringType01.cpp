//
//  StringType01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 14/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <cstring>
#include "StringType01.hpp"

namespace DynamicClasses201
{
    // Initialise static class member
    int String::s_strCount = 0;
    
//  Static methods
    int String::stringCount()
    {
        return s_strCount;
    }
    
//  Cosntructors and destructor
    String::String(const char* s)                       // Construct from a C-string
    {
        m_length = static_cast<int>(std::strlen(s));    // set string size
        m_str = new char[m_length + 1];                 // allot storage
        std::strcpy(m_str, s);                          // initialise allocated storage
        s_strCount++;                                   // update object count
        
    #ifdef VERBOSE_STRING_
        std::cout << s_strCount << ": \"" << m_str << "\" object created\n";
    #endif
    }
    
    String::String()                                    // Default constructor
    {
        m_length = 0;
        m_str = new char[1];
        m_str[0] = '\0';                                // create empty string
        s_strCount++;
        
    #ifdef VERBOSE_STRING_
        std::cout << s_strCount << ": Empty object created\n";
    #endif
    }
    
    String::String(const String& s)                     // Explicit copy constructor
    {
        m_length = s.m_length;                          // same length
        m_str = new char[m_length + 1];                 // allot space
        std::strcpy(m_str, s.m_str);                    // copy string to new location
        s_strCount++;                                   // update object count
        
    #ifdef VERBOSE_STRING_
        std::cout << s_strCount << ": \"" << m_str << "\" object copied\n";
    #endif
    }
    
    String::~String()                                   // Necessary destructor
    {
    #ifdef VERBOSE_STRING_
        std::cout << "\"" << m_str << "\" object being deleted, "
                  << s_strCount - 1 << " strings left... ";
    #endif
        
        s_strCount--;                                   // required
        delete [] m_str;                                // required
        
    #ifdef VERBOSE_STRING_
        std::cout << "Done.\n";
    #endif
    }
    
//  Assignment operators
    String& String::operator=(const String& s)
    {
        if (this == &s)                                 // prevent self-copying
            return *this;
        
        delete [] m_str;                                // release memory of old string
        m_length = s.m_length;                          // same length
        m_str = new char[m_length + 1];                 // allocate memory for new string
        std::strcpy(m_str, s.m_str);                    // copy the string contents
        
        // NB! No new objects created, so don't increment strCount!
        
    #ifdef VERBOSE_STRING_
        std::cout << "Assigned \"" << m_str << "\" String object\n";
    #endif
        
        return *this;                                   // return reference to envoking object
    }
    
    String& String::operator=(const char* s)
    {
        delete [] m_str;
        m_length = static_cast<int>(std::strlen(s));
        m_str = new char[m_length + 1];
        std::strcpy(m_str, s);
        
    #ifdef VERBOSE_STRING_
        std::cout << "Assigned \"" << m_str << "\" C-string\n";
    #endif
        
        return *this;
    }
    
//  Element access operators
    char& String::operator[](int i)                     // read/write version, no bounds checking
    {
        return m_str[i];
    }
    
    const char& String::operator[](int i) const         // read-only version, no bounds checking
    {
        return m_str[i];
    }
    
//  Comparison operators
    bool operator<(const String& st1, const String& st2)
    {
        return (std::strcmp(st1.m_str, st2.m_str) < 0);
    }
    
    bool operator>(const String& st1, const String& st2)
    {
        return (std::strcmp(st1.m_str, st2.m_str) > 0);
    }
    
    bool operator==(const String& st1, const String& st2)
    {
        return (std::strcmp(st1.m_str, st2.m_str) == 0);
    }
    
//  I/O operators
    std::ostream& operator<<(std::ostream& os, const String& s)     // Simple string output
    {
        os << s.m_str;
        return os;
    }
    
    std::istream& operator>>(std::istream& is, String& s)   // Quick and dirty String input
    {
        char temp[String::CINLIM];      // temporary buffer
        is.get(temp, String::CINLIM);
        
        if(is)                          // if not failstate
            s = temp;
        
        while(is && is.get() != '\n')   // if not failstate and characters trailing clear them
            continue;
        
        return is;
    }
}   // end namespace DynamicClasses201
