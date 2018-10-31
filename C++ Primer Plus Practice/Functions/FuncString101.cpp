//
//  FuncString101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 02/10/2018.
//

#include <iostream>

constexpr int Limit {15};

//  Function prototypes
unsigned int charCount(const char * input, char ch);

void showFuncString101()
{
    char array[Limit] {"minimum"};      // string in an array
    const char * pointer {"lollipop"};  // pointer to string
    
    unsigned int mCount {charCount(array, 'm')};
    unsigned int oCount {charCount(pointer, 'o')};
    
    std::cout
        << mCount << " m characters in " << array << "\n"
        << oCount << " o characters in " << pointer << "\n";
}

unsigned int charCount(const char* p_in, char ch)
{
    unsigned int count {};
    while (*p_in)      // while char at p_in is not '\0'
    {
        if (*p_in == ch)
            ++count;
        ++p_in;         // move p_in to the next character
    }
    return count;
}
