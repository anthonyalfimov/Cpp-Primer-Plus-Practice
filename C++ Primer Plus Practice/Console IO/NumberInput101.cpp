//
//  NumberInput101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 24/09/2018.
//

#include <iostream>

constexpr int Max {5};

// NB! This program doesn't use input after fail flag is set for cin
// if we were to keep using input, we'd have to reset cin and flush the buffer
// - See NumberInput102

void showNumberInput101()
{
// get data
    double fish[Max];
    std::cout << "Please enter the weights of your fish.\n"
                 "You may enter up to " << Max << " fish. "
                 "<q to terminate>\n\n";
    
    std::cout << "fish #1: ";
    int i {};
    while (i < Max && std::cin >> fish[i])
        if (++i < Max)
            std::cout << "fish #" << i + 1 << ": ";
    
// calculate total
    double total {};
    for (int j = 0; j < i; ++j)
        total += fish[j];
    
// report the results
    if (i == 0)
        std::cout << "No fish!\n";
    else
        std::cout << total / i << " average weight out of "
                  << i << " fish.\n";
    
    std::cout << "Done.\n";
}
