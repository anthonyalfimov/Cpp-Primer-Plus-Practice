//
//  ConstCast101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/12/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>

namespace
{
    void updateValue(const int* original, int newValue);
}

void showConstCast101()
{
    int value1 = 38383;
    const int value2 = 2000;
    
    std::cout << "value1, value2: " << value1 << ", " << value2 << "\n";
    
    updateValue(&value1, 2000);
    updateValue(&value2, 300);      // NB! Undefined behaviour - attempting to change const object
    
    std::cout << "value1, value2: " << value1 << ", " << value2 << "\n";
}

namespace
{
    void updateValue(const int* original, int addValue)
    {
        int* accessOriginal = const_cast<int*> (original);
        *accessOriginal += addValue;
    }
}
