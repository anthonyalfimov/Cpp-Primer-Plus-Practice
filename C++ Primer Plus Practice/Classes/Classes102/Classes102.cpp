//
//  Classes102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 28/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "Stock02.hpp"

constexpr int size {4};

void showClasses102()
{
    using namespace Classes102;
    
//  Create an array of initialized objects (use list initialization)
    Stock stocks[size]
    {
        {"NanoSmart", 12, 20.0},
        {"Boffo Objects", 200, 2.0},
        {"Monolithic Obelisks", 130, 3.25},
        {"Fleep Enterprises", 60, 6.5}
    };
    
    std::cout << "Stock holdings:\n";
    for (int i = 0; i < size; i++)
        stocks[i].show();
    
//  Set a pointer to the first element
    const Stock* top = &stocks[0];
    
    for (int i = 1; i < size; i++)
        top = &top->topValue(stocks[i]);    // `->` is higher precedense than `&-address`
    
//  Display the most valuable holding
    std::cout << "\nMost valuable holding:\n";
    top->show();
}
