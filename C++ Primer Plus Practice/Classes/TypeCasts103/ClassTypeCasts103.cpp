//
//  ClassTypeCasts103.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 29/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  This file looks into how implicit type casts function with operator overloading
//

#include <iostream>
#include "StonewtType03.hpp"

void showClassTypeCasts103()
{
    using namespace ClassTypeCasts103;
    
    Stonewt alpha {9, 12.1};
    alpha.showPounds();
    std::cout << "\n";
    
    // If conversion function to double is not explicit, this expression is ambiguous
    Stonewt beta = alpha + 176.0;
    beta.showStone();
    std::cout << "\n";
    
    // If operator+ overload was a member function, this wouldn't work
    Stonewt gamma = 25.2 + alpha;
    gamma.showPounds();
    std::cout << "\n";
    
    // Use type cast to perform 'double' addition and then cast the result to 'Stonewt'
    //    due to explicit cast here, this statement would work even if conversion function to
    //    double wasn't specified as explicit - ambiguity would be resoved manually
    alpha = double(beta) + 10.0;
    alpha.showStone();
    std::cout << "\nDone.\n";
    
}
