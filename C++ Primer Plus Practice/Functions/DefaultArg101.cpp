//
//  DefaultArg101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 18/10/2018.
//

#include <iostream>
#include <cstring>

namespace DefaultArg101
{
    const int Size {80};
//    Function prototype with default value for the last argument
    /**
     Function returns a pointer to a new string
     consisting of the first n characters in the str string

     @return pointer to a new string
     consisting of the first n characters in the str string
     */
    char * left(const char * str, int n = 1);
}

using namespace DefaultArg101;

void showDefaultArg101()
{
    char sample[Size];
    std::cout << "Enter a string:\n";
    std::cin.getline(sample, Size);
    
    char* ps = left(sample, 4);
    std::cout << ps << "\n";
    delete [] ps;
    
    ps = left(sample);
    std::cout << ps << "\n";
    delete [] ps;
}

char * DefaultArg101::left(const char * str, int n)
{
    if (n < 0) n = 0;
    
//    Implementation of this function is enhanced in the
//    FuncOverload101 file
    
    char* p = new char[n + 1];
    int i;
    for (i = 0; i < n && str[i]; i++)   // check for '\0' in case n > string length
        p[i] = str[i];      // copy characters
    while (i <= n)
        p[i++] = '\0';      // set rest of string to null character
    return p;
}
