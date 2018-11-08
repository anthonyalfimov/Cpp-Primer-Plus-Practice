//
//  LocalStaticVars101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 08/11/2018.
//
//  BONUS: How to deal with line input that might exceed the size of destination array
//

#include <iostream>

namespace LocalStaticVars101
{
//  Constants:
    constexpr int size {10};
    
//  Fucntion prototype:
    void strCount(const char* str);
}

using namespace LocalStaticVars101;

void showLocalStaticVars101()
{
    char input[size];
    char next;
    
    std::cout << "Enter a line:\n";
    std::cin.get(input, size);      // leave '\n' in the buffer
    while(std::cin)
    {
        std::cin.get(next);         // '\n' if the string did fit
        while (next != '\n')        // string didn't fit
            std::cin.get(next);     // dispose of the remainder
        strCount(input);
        std::cout << "Enter next line (empty line to quit):\n";
        std::cin.get(input, size);  // leave '\n' in the buffer
    }
    std::cout << "Done.\n";
}

void LocalStaticVars101::strCount(const char* str)
{
    static int total = 0;       // static local variable
                                // - only initialized on creation
    int count = 0;              // automatic local variable
                                // - initialized every time the function is run
    
    std::cout << "\"" << str << "\" contains ";
    while (*str++)              // go until the '\0' termintaing the string
        count++;
    total += count;
    std::cout
        << count << " characters.\n"
        << total << " characters total.\n";
}
