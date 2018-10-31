//
//  StringFun104.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 20/07/2018.
//

#include <iostream>
#include <string>
#include <cstring>

void showStringFun104()
{
    int size {20};
    char charr[size];
    std::string str;
    
    std::cout << "Length of string in charr before input: "
              << std::strlen(charr) << "\n"
              << "Length of string in str before input: " << str.length() << "\n"
              << "Enter a line of text:\n";
    std::cin.getline(charr, size);          // cin member function invoked
    std::cout << "You entered: " << charr << "\n"
              << "Enter another line of text:\n";
    std::getline(std::cin, str);            // standalone function invoked with cin as a parameter
    std::cout << "You entered: " << str << "\n"
              << "Length of string in charr after input: "
              << std::strlen(charr) << "\n"
              << "Length of string in str after input: " << str.length() << "\n";
}
