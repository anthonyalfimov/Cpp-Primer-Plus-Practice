//
//  coord.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 01/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "coord.hpp"    // struct templates, function prototypes

namespace Headers101
{
    Polar rectToPolar(Rect xy)
    {
        Polar result;
        result.radius = std::sqrt(xy.x * xy.x + xy.y * xy.y);
        result.angle = std::atan2(xy.y, xy.x);
        
        return result;
    }

    void  showPolar(Polar ra)
    {
        const double radToDeg {57.29577951};
        
        std::cout
        << "Radius = " << ra.radius
        << ", angle = " << ra.angle * radToDeg << " degrees.\n";
    }
}

