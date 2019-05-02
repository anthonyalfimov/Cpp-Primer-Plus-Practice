//
//  Inheritance502.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 02/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstring>          //  for strchr() - return address of char in C-string, null if not found
#include "Worker02.hpp"

const int size = 5;

void showMultipleInheritance101()
{
    using Inheritance502::Worker;
    using Inheritance502::Singer;
    using Inheritance502::Waiter;
    using Inheritance502::SingingWaiter;
    
    Worker* staff[size];
    
    int ct;
    
    for (ct = 0; ct < size; ct++)
    {
        char choice;
        std::cout << "Enter the employee category:\n"
                  << "w: waiter   s: singer   t: singing waiter   q: quit\n";
        
        std::cin >> choice;
        
        while (std::strchr("wstq", choice) == nullptr)
        {
            std::cout << "Please enter \"w\", \"s\", \"t\" or \"q\": ";
            std::cin >> choice;
        }
        
        if (choice == 'q')
        {
            std::cout << "\n";
            break;
        }
        
        switch(choice)
        {
            case 'w':   staff[ct] = new Waiter;
                        break;
            case 's':   staff[ct] = new Singer;
                        break;
            case 't':   staff[ct] = new SingingWaiter;
                        break;
        }
        
        std::cin.get();
        staff[ct]->set();
        std::cout << "\n";
    }
    
    std::cout << "Here is your staff:\n";
    
    for (int i = 0; i < ct; i++)
    {
        std::cout << "\n";
        staff[i]->show();
    }
    
    for (int i = 0; i < ct; i++)
        delete staff[i];
    
    std::cout << "\nDone.\n";
}
