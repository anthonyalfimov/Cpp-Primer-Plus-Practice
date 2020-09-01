//
//  Vector101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 19/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// std::vector basic intro
//==================================================================================================

#include <iostream>
#include <string>
#include <vector>

static const int bookCount = 5;

void showStdVector101()
{
    std::vector<int> bookRatings (bookCount);
    std::vector<std::string> bookTitles (bookCount);
    
    std::cout << "Please enter " << bookCount << " book titles and your ratings (0-10).\n";
    
    for (int i = 0; i < bookCount; ++i)
    {
        std::cout << "Enter title #" << i + 1 << ": ";
        std::getline (std::cin, bookTitles[i]);
        std::cout << "Enter your rating (0-10): ";
        std::cin >> bookRatings[i];
        std::cin.get();
    }
    
    std::cout << "\nThank you. You entered the following:\nRating\tBook\n";
    
    for (int i = 0; i < bookCount; ++i)
        std::cout << bookRatings[i] << "\t\t" << bookTitles[i] << "\n";
    
    std::cout << "\nDone.\n";
}
