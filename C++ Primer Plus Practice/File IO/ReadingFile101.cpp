//
//  ReadingFile101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 25/09/2018.
//

#include <iostream>
#include <fstream>      // file I/O support
#include <cstdlib>      // support for exit()

constexpr int Size {60};

void showReadingFile101()
{
    char filename[Size];
    std::ifstream inFile;   // object for handling file input
    
    std::cout << "Enter name of data file: ";
    std::cin.getline(filename, Size);
    inFile.open(filename);  // associate inFile with a file
    if (!inFile.is_open())  // failed to open the file
    {
        std::cout << "Could not open the file " << filename << "\n"
                  << "Program terminating.\n";
        exit(EXIT_FAILURE); // <cstdlib> function that communicated failure to the OS
    }
    double value {};
    double sum {};
    int count {};           // number of items read
    
    inFile >> value;        // get the first value
    while (inFile.good())   // while input good and not at EOF
                            // can be replaced with 'while(inFile >> value)'
    {
        ++count;            // increment the count of read items
        sum += value;       // calculate running total
        inFile >> value;    // get the next value
    }
    
// assessing the reason for input termination
    if (inFile.eof())
        std::cout << "End of file reached.\n";
    else if (inFile.fail())
        std::cout << "Input terminated by data mismatch.\n";
    else
        std::cout << "Input terminated for unknown reason.\n";
    
// reporting the results
    if (count == 0)
        std::cout << "No data processed.\n";
    else
        std::cout << "Items read: " << count
                  << "\nSum: " << sum
                  << "\nAverage: " << sum / count << "\n";
    
    inFile.close();
}
