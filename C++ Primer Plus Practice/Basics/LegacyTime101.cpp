//
//  LegacyTime101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 21/08/2018.
//

// Legacy timing tools

#include <iostream>
#include <ctime>

void showLegacyTime101()
{
    std::cout << "Enter the delay time, in seconds: ";
    float secs;
    std::cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;  // use type alias clock_t and preprocessor constant
                                            // calculate delay time in system units
    
    std::cout << "Starting...\n";
    unsigned long long iterations {};
    clock_t start = clock();
    while (clock() - start < delay)
        ++iterations;                       // wait and count iterations
    
    std::cout << "Done after " << iterations << " iterations!\n";
}
