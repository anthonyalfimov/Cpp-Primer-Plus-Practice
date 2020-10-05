//
//  STLandString101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/10/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// STL-compatible interface of std::string
//==================================================================================================

#include <iostream>
#include <string>
#include <algorithm>

void showSTLandString101()
{
    std::string letters;
    std::cout << "Enter the letter grouping ('quit' to quit): ";
    
    while (std::cin >> letters && letters != "quit")
    {
        std::cout << "Permutations of " << letters << "\n";
        std::sort (letters.begin(), letters.end());
        
        do
            std::cout << letters << "\n";
        while (std::next_permutation (letters.begin(), letters.end()));
        
        std::cout << "\nEnter next sequence ('quit' to quit): ";
    }
    
    std::cout << "\nDone.\n";
}
