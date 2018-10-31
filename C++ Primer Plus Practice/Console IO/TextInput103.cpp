//
//  TextInput103.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/09/2018.
//
// =================================
// Condensed version of TextInput102
// =================================

#include <iostream>

// this file uses EOF condition to terminate input
// use with simulated EOF or redirection

void showTextInput103()
{
    char ch;
    int count {};
    std::cout << "103 | Input characters. Use Ctrl + D on a new line on Mac for simulated EOF.\n";
    
    while (std::cin.get(ch))     // test for input failure
                                 // cin.get(char) returns cin that is converted to bool
    {
        std::cout << ch;
        ++count;
    }
    std::cout << "\n" << count << " characters read.\n";
}
