//
//  StdString102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// std::string input
//==================================================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void showStdString102()
{
    std::ifstream inputFile;
    inputFile.open ("StdStringInput.csv");
    
    if (inputFile.is_open() == false)
    {
        std::cerr << "Can't open file. Terminating...\n";
        std::exit (EXIT_FAILURE);
    }
    
    std::string item;
    int itemCount = 0;
    
    std::getline (inputFile, item, ',');
    
    while (inputFile)   // while input is good
    {
        ++itemCount;
        std::cout << itemCount << ": " << item << "\n";
        std::getline (inputFile, item, ',');
    }
    
    if (inputFile.eof() == true)
        std::cout << "Reached end of file.\n";
    
    std::cout << "\nDone.\n";
    inputFile.close();
}
