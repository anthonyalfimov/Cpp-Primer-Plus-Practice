//
//  ClassArray101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 28/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "Stock01.hpp"

void showClassArray101()
{
    using namespace Classes101;
    
    // Initialize using a list of constructors
    Stock bundle[3] =
    {
        Stock("Bundle 1"),
        Stock("Bundle 2"),
        Stock("Bundle 3", 12, 3.5)
    };
    
    // Initialize using a list of list initializers
    Stock pack[2]
    {
        {"Pack 1", 50},
        {"Pack 2", 240, 12.5}
    };
}
