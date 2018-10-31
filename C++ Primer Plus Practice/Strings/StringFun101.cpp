//
//  StringFun101.cpp
//  C++ Primer Plus Exercises
//
//  C-style strings using arrays
//

#include <iostream>

void showStringFun101()
{
    std::cout << "What year was your house built?\n";
    
    int year;
    (std::cin >> year).get();       // cin leaves the '\n' in the input buffer
                                    // demonstrating concatenation of cin operations / member calls
    
    std::cout << "What is its street address?\n";
    constexpr int address_size {80};
    char address[address_size];
    std::cin.getline(address, address_size);
    
    std::cout << "Year built: " << year << "\n"
    << "Address: " << address << "\n"
    << "Done!\n";
}
