//
//  Vector102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 17/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "RandomWalk01.hpp"

namespace
{
    unsigned long theoreticalSteps(double distance, double step)
    { return (distance / step) * (distance / step); }
}

void showVector102()
{
    using Vector100::RandomWalk;
    using Vector100::Vector2;
    
    // Random walk set parameters
    double        distance;      // target distance from origin
    double        step;          // step length
    unsigned int  trials;        // number of trials in a set
    
    RandomWalk    walk(0, 0);    // random walk results
    
    // Statistical characteristics of a set of random walks
    Vector2       avPosition;    // average end position
    unsigned long avSteps;       // average number of steps
    unsigned long minSteps;
    unsigned long maxSteps;

    std::cout << "Enter target distance (q to quit): ";
    while (std::cin >> distance)
    {
        std::cout << "Enter step length: ";
        if (!(std::cin >> step))
            break;
        
        std::cout << "Enter number of trials: ";
        if (!(std::cin >> trials) || trials < 1)
            break;
        
        if (trials > 100000)
        {
            std::cout << "Too many trials, bad idea!\n\n";
            std::cout << "Enter target distance (q to quit): ";
            continue;
        }
        
        // Perform the set of random walks
        walk.reset(distance, step);
        
        // Initialize the stats:
        avPosition = avPosition + walk.endPosition;
        avSteps = walk.steps;
        minSteps = maxSteps = walk.steps;
        
        for (int i = 1; i < trials; i++)
        {
            walk.reset(distance, step);
            avPosition = avPosition + walk.endPosition;
            avSteps += walk.steps;
            
            if (walk.steps > maxSteps)
                maxSteps = walk.steps;
            else if (walk.steps < minSteps)
                minSteps = walk.steps;
        }
        
        // Calculate averages:
        avPosition = avPosition * (1.0 / trials);
        avSteps /= trials;
        
        // Report the results
        
        std::cout
            << "\nTheoretical mean number of steps: " << theoreticalSteps(distance, step) << "\n"
            << "Mean number of steps after " << trials << " trials: " << avSteps << ",\n"
            << "with number of steps varied between " << minSteps
            << " and " << maxSteps << " steps\n"
            << "\nThe average end position:\n"
            << avPosition << "\n";
        avPosition.polarMode();
        std::cout
            << "or\n" << avPosition << "\n";
        
        std::cout << "\nEnter target distance (q to quit): ";
    }
    std::cout << "\nDone.\n";
    
    std::cin.clear();
    while (std::cin.get() != '\n')
        continue;
}
