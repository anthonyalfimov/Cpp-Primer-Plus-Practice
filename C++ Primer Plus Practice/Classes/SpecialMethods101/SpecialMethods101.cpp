//
//  SpecialMethods101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  This short program demonstrate how a typecast-defining constuctor
//      and an assginment operator overload for a different type can
//      be used together
//

#include "MagicNumber01.hpp"

void showSpecialMethods101()
{
    using SpecialMethods101::MagicNumber;
    
    MagicNumber foo = 5;
    MagicNumber bar(3);
    
    foo = 7;
}
