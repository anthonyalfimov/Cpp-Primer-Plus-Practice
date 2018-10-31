//
//  TextInput102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/09/2018.
//

#include <iostream>

// this file uses EOF condition to terminate input
// use with simulated EOF or redirection

void showTextInput102()
{
    char ch;
    int count {};
    std::cout << "102 | Input characters. Use Ctrl + D on a new line on Mac for simulated EOF.\n";
    std::cin.get(ch);           // attempt to read a char
    
    while (!std::cin.eof())     // test for EOF | or use cin.fail() for (EOF or failbit) check
    {
        std::cout << ch;
        ++count;
        std::cin.get(ch);
    }
    std::cout << "\n" << count << " characters read.\n";
}
