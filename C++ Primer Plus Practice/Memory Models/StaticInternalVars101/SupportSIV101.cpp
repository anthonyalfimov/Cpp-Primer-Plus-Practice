//
//  SupportSIV101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 08/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

extern int siv_tom;         // reference declaration
static int siv_dick {10};   // static, internal linkage - hides external dick
int siv_harry {200};        // external variable definition
                            // no conflict with main file harry

void siv_remoteAccess()
{
    std::cout
    << "remoteAccess() reports the following addresses:\n"
        << "&tom = " << &siv_tom
        << ", &dick = " << &siv_dick
        << ", &harry = " << &siv_harry << "\n";
}
