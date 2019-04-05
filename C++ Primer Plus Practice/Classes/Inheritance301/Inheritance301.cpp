//
//  Inheritance301.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "DMA01.hpp"

void showInheritance301()
{
    using Inheritance300::BaseDMA;
    using Inheritance300::LacksDMA;
    using Inheritance300::HasDMA;
    
    BaseDMA  shirt("Portabelly", 8);
    LacksDMA balloon("Blimpo", 4, "red");
    HasDMA   map("Buffalo Keys", 5, "Mercator");
    
    std::cout
        << "Displaying BaseDMA object:\n"
        << shirt << "\n"
        << "Displaying LackDMA object:\n"
        << balloon << "\n"
        << "Displaying HasDMA object:\n"
        << map << "\n";
    
    LacksDMA balloon2(balloon);
    std::cout
        << "Result of LackDMA copy:\n"
        << balloon2 << "\n";
    
    HasDMA map2;
    map2 = map;
    std::cout
        << "Result of HasDMA assignment:\n"
        << map2 << "\n";
}
