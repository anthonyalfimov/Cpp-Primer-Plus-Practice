//
//  AutomaticVars101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 06/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>

void oil(int x);

void showAutomaticVars101()
{
    int texas {31};
    int year {2018};
    
    std::cout
        << "In main(), texas = " << texas << ", &texas = " << &texas << "\n"
        << "In main(), year = " << year << ", &year = " << &year << "\n";
    
    oil(texas);
    
    std::cout
        << "In main(), texas = " << texas << ", &texas = " << &texas << "\n"
        << "In main(), year = " << year << ", &year = " << &year << "\n";
}

void oil(int x)
{
    int texas {5};
    
    std::cout
        << "In oil(),  texas = " << texas << ", &texas = " << &texas << "\n"
        << "In oil(),  x = " << x << ", &x = " << &x << "\n";
    
    {                   // start block
        int texas {113};
        std::cout
            << "In block,  texas = " << texas << ", &texas = " << &texas << "\n"
            << "In block,  x = " << x << ", &x = " << &x << "\n";
    }                   // end block
    
    std::cout
        << "Post block, texas = " << texas << ", &texas = " << &texas << "\n";
}
