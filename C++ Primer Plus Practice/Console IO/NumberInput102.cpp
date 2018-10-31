//
//  NumberInput102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 24/09/2018.
//

#include <iostream>

constexpr int Max {5};

void showNumberInput102()
{
// get data
    int golfScores[Max];
    std::cout << "Enter your golf scores.\n"
                 "You must enter " << Max << " rounds.\n";
    for (int i = 0; i < Max; ++i)
    {
        std::cout << "round #" << i + 1 << ": ";
        while (!(std::cin >> golfScores[i]))
        {
            std::cin.clear();   // reset the input
            while (std::cin.get() != '\n')
                continue;       // naive buffer ignore
            std::cout << "MUST be a number: ";
        }
    }
// calculate total
    double total {};
    for (int score : golfScores)        // range-based for loop
        total += score;
    
    // report results
    std::cout << total / Max << " average score for "
              << Max << " rounds.\n";
}
