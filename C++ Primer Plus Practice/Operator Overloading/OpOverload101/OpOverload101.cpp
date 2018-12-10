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
    
//  Operator notation
    total = coding + fixing;
    std::cout << "coding + fixing = ";
    total.show();
    std::cout << std::endl;
    
    Time moreFixing(3, 28);
    std::cout << "more fixing time = ";
    moreFixing.show();
    std::cout << std::endl;
    
//  Function notation
    total = moreFixing.operator+(total);
    std::cout << "moreFixing.operator+(total) = ";
    total.show();
    std::cout << std::endl;
}
