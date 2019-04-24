//
//  WorkerTest01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 24/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Worker01.hpp"

const int size = 4;

void showWorkerTest01()
{
    using Inheritance501::Worker;
    using Inheritance501::Waiter;
    using Inheritance501::Singer;
    
    Waiter bob("Bob Apple", 314L, 5);
    Singer bev("Beverly Hills", 522L, 3);
    
    Waiter w_temp;
    Singer s_temp;
    
    Worker* pw[size] =
    {
        &bob, &bev, &w_temp, &s_temp
    };
    
    int i;
    for (i = 2; i < size; i++)
    {
        pw[i]->set();
        std::cout << "\n";
    }
    
    for (i = 0; i < size; i++)
    {
        pw[i]->show();
        std::cout << "\n";
    }
    
    std::cout << "\nDone.\n";
}
