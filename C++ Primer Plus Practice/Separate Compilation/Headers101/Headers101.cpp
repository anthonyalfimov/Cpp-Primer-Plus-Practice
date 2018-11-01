//
//  Headers101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 01/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "coord.hpp"    // struct templates, function prototypes

using namespace Headers101;

void showHeaders101()
{
    Rect rplace;
    Polar pplace;
    
    std::cout << "Enter the x and y values: ";
    while (std::cin >> rplace.x >> rplace.y)    // while input for both values is good
    {
        pplace = rectToPolar(rplace);
        showPolar(pplace);
        std::cout << "Next pair of values <q to quit>: ";
    }
    
    std::cout << "\nDone!\n";
}
