//
//  WritingFile101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 24/09/2018.
//

#include <iostream>
#include <fstream>      // for file I/O

constexpr int stringSize {50};

void showWritingFile101()
{
    char automobile[stringSize];
    int year;
    double askPrice;
    double dealPrice;
    
    std::ofstream outFile;          // create an object for output
    outFile.open("carinfo.txt");    // associate with a file
    
    std::cout << "Enter the make and model of automobile: ";
    std::cin.getline(automobile, stringSize);
    std::cout << "Enter the model year: ";
    std::cin >> year;
    std::cout << "Enter the original asking price: ";
    std::cin >> askPrice;
    dealPrice = askPrice * 0.913;
    
// display information on the screen with cout:
    
    std::cout << std::fixed;        // write floating-point values in fixed-point notation
    std::cout.precision(2);         // set floating-point decimal precision
    std::cout.setf(std::ios_base::showpoint);   // enable unconditional inclusion of decimal point
    
    std::cout << "Make and model: " << automobile << "\n"
              << "Year: " << year << "\n"
              << "Was asking: $" << askPrice << "\n"
              << "Now asking: $" << dealPrice << "\n";
    
// now repeat the same using the outFile object instead of cout
    
    outFile << std::fixed;      // write floating-point values in fixed-point notation
    outFile.precision(2);       // set floating-point decimal precision
    outFile.setf(std::ios_base::showpoint);     // enable unconditional inclusion of decimal point
    
    outFile << "Make and model: " << automobile << "\n"
            << "Year: " << year << "\n"
            << "Was asking: $" << askPrice << "\n"
            << "Now asking: $" << dealPrice << "\n";
    
    outFile.close();        // close the file
}
