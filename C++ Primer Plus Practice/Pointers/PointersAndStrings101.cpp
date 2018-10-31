//
//  PointersAndStrings101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 06/08/2018.
//

#include <iostream>

void  showPointersAndStrings101()
{
    // If cout is given a char pointer, it prints everything
    // starting from that character until '\0' is encountered
    
    char * test {new char};
    *test = 'A';
    *(test + 1) = 'B';      // add additional characters in memory
    *(test + 2) = 'C';
    std::cout << test << "\n";
    delete test;
    
    // A quoted string literal is generally interpreted
    // as an address to the first character
    
    const char * literal = "Test String";   // Assigning address of the first character
                                            // of the string literal to a pointer.
                                            // String literals can be stored within the
                                            // binary of the program, hence const pointer.
    
    char indicator {'X'};
    std::cout << indicator << "\n";
    indicator = *literal;
    std::cout << indicator << "\n";
}
