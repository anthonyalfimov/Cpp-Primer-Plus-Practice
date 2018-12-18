//
//  RandomWalk01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 17/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//
//  Updated version of the random walk implementation that allows
//      to collect statistics on the random walk and provides a choice
//      between C-style random numbers and modern <random> header
//

#ifndef RandomWalk01_hpp
#define RandomWalk01_hpp

#include "Vector2Type01.hpp"

namespace Vector100
{
    class RandomWalk
    {
    public:
        // Public data members (output of the object, making public for simplicity)
        Vector2       endPosition;
        unsigned long steps;
        
    private:
        // Random walk parameters
        double        m_distance;
        double        m_step;
        
        // Random generation seed
        unsigned      m_seed;
        
    public:
        RandomWalk(double     distance,
                   double     step);
        
        void reset(double     distance,
                   double     step);
        
        /**
         Returns average outward displacement per step if number of steps is valid (positive),
         zero otherwise
         */
        double meanDisplacement() { return steps > 0 ? endPosition.getR() / steps : 0; }

    };
}

#endif /* RandomWalk01_hpp */
