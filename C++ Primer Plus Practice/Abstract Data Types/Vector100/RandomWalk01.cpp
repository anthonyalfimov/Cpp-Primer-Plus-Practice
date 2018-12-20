//
//  RandomWalk01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 17/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
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

#include "RandomWalk01.hpp"

namespace Vector100
{
//  RandomWalk
    
    // Public methods
    RandomWalk::RandomWalk(double distance, double step)
    {
        // NB! With this approach, if more than one RandomWalk object is created during the
        //     same second, the sequence of random numbers will be the same for them
        
        // If you want to use more than one object, best choice is to switch to <random>
        //     Alternatively, use more precise time to seed.
        
        // Override the default seed value for the pseudorandom number generator
        //     so that each run of the program generates different sequence of random numbers
        std::srand(static_cast<unsigned>(time(0)));
        reset(distance, step);
    }
    
    void RandomWalk::reset(double distance, double step)
    {
        m_distance = distance;
        m_step     = step;
        
        // Perform the random walk
        steps = 0;
        endPosition.reset();
        
        Vector2 displacement;       // random walk step vector
        double  direction;          // random walk step direction

        while (endPosition.getR() < distance)
        {
            // Get a random angle value in [0, 359]
            direction = std::rand() % 360;
            displacement.reset(step, direction, Vector2::POL);
            
            // This sets result to RECT mode as a result of operator+() using the
            //     default constructor, and the assignment operation using the
            //     implicit copy-constructor.
            endPosition = endPosition + displacement;
            steps++;
        }
    }
    
//  end RandomWalk
}
