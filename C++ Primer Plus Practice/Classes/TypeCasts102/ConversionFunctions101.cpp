//
//  ConversionFunctions101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 24/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "StonewtType02.hpp"

void showConversionFunctions101()
{
    using namespace ClassTypeCasts102;
    
    Stonewt poppins(9, 2.8);        // 9 stone, 2.8 pounds
    double p_wt = poppins;          // implicit conversion
    
    std::cout << "Convert to double => Poppins: " << p_wt << " pounds.\n";
    std::cout << "Convert to int    => Poppins: " << int (poppins) << " pounds.\n";
    
    // This is possible because only one implicit conversion is available - no ambiguity
    std::cout << "Implicit conversion: " << poppins << " pounds.\n";
}
