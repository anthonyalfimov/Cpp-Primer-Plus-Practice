//
//  OpOverload102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "myTime01.hpp"

void showOpOverload102()
{
    using namespace OpOverload100;
    
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;
    
    std::cout << "Weeding time = ";
    weeding.show();
    std::cout << "\n";
    
    std::cout << "Waxing time = ";
    waxing.show();
    std::cout << "\n";
    
    std::cout << "Total work time = ";
    total = weeding + waxing;
    total.show();
    std::cout << "\n";
    
    std::cout << "Weeding time - waxing time = ";
    diff = weeding - waxing;
    diff.show();
    std::cout << "\n";
    
    std::cout << "Adjusted work time = ";
    adjusted = total * 1.5;
    adjusted.show();
    std::cout << "\n";
}
