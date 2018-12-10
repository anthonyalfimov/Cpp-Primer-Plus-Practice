//
//  OpOverload101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 10/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "myTime01.hpp"

void showOpOverload101()
{
    using namespace OpOverload101;
    
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
    
    std::cout << "Planning time = ";
    planning.show();
    std::cout << std::endl;
    
    std::cout << "Coding time = ";
    coding.show();
    std::cout << std::endl;
    
    std::cout << "Fixing time = ";
    fixing.show();
    std::cout << std::endl;
    
    total = coding.sum(fixing);
    std::cout << "coding.sum(fixing) = ";
    total.show();
    std::cout << std::endl;
}
