//
//  MultipleInheritance102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 04/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Worker02.hpp"

void showMultipleInheritance102()
{
    using namespace Inheritance502;
    
    SingingWaiter source("Eva Bluefield", 1701L, 10, 3);
    source.show();
    std::cout << "\n";
    
    SingingWaiter destination(source);      // use implicit copy-ctor
    destination.show();                     // implicit copy-ctor works here,
                                            //     but it is safer to provide explicit copy-ctor
                                            //     when using virtual inheritance
}
