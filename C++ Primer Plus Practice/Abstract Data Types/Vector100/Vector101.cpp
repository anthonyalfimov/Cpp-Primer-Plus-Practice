//
//  RandomWalk01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 17/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
                                //
                                // NB! For realprojects use funtions from <random> instead
                                //
#include <cstdlib>              // Standard ANSI C lib for: rand(), srand()
                                //     rand() returns a pseudorandom integer
                                //     (by applying a deterministic algorithm to a seed value)
                                //     from 0 to some implementation-determined value

#include <ctime>                // time(0) - returns the current calendar time, usually in
                                //     number of seconds since some set date
                                // Generally, time() function takes an address of a type
                                //     `tyme_t` variable, puts the time into this variable
                                //     and also returns it. Using `0` as the address obviates
                                //     the need for the unnecessary in our case variable
#include "Vector2Type01.hpp"

void showVector101()
{
    using Vector100::Vector2;
    
    // Override the default seed value for the pseudorandom number generator
    //     so that each run of the program generates different sequence of random numbers
    std::srand(static_cast<unsigned int>(time(0)));
    
    double direction;
    Vector2 step;
    Vector2 result(0.0, 0.0);
    unsigned long stepCount {0};
    double target;
    double dstep;
    
    std::cout << "Enter target distance (q to quit): ";
    while (std::cin >> target)
    {
        std::cout << "Enter step length: ";
        if (!(std::cin >> dstep))
            break;
        
        while (result.getR() < target)
        {
            // Get a random angle value in [0, 359]
            direction = std::rand() % 360;
            
            step.reset(dstep, direction, Vector2::POL);
            
            // This sets result to RECT mode as a result of operator+() using the
            //     default constructor, and the assignment operation using the
            //     implicit copy-constructor.
            result = result + step;
            // To preserve the mode, a custom copy-constructor should be used
            
            stepCount++;
        }
        
        // Report the results
        std::cout
            << "After " << stepCount << " steps, the subject "
            << "has the following location:\n"
            << result << "\n";
        result.polarMode();
        std::cout
            << "or\n" << result << "\n"
            << "Average outward displacement per step is "
            << result.getR() / stepCount << "\n";
        
        // Reset the values for another calculation
        stepCount = 0;
        result.reset();
        
        std::cout << "\nEnter target distance (q to quit): ";
    }
    std::cout << "\nDone.\n";
    
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
}
