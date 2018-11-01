//
//  coord.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 01/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef coord_hpp
#define coord_hpp

namespace Headers101
{
    struct Polar        // polar coordinates
    {
        double radius;
        double angle;
    };
    
    struct Rect         // cartesian coordinates
    {
        double x;
        double y;
    };
    
//    Function prototypes
    Polar rectToPolar(Rect xyPos);
    void  showPolar(Polar raPos);
}

#endif /* coord_hpp */
