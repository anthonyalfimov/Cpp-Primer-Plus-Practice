//
//  ClassTemplates203.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 08/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Example of member templates
//

#include <iostream>
#include "NestedTemplate01.hpp"

void showClassTemplates203()
{
    using ClassTemplates203::Beta;
    
    Beta<double> guy(3.5, 3);
    std::cout << "Q was set to double\n\n";
    
    guy.show();
    std::cout << "V was set to Q (double), then V was set to int\n\n";
    
    std::cout << guy.calculate(10, 2.3) << "\n";
    std::cout << "T was set to int\n\n";
    
    std::cout << guy.calculate(10.0, 2.3) << "\n";
    std::cout << "T was set to double\n";
}
