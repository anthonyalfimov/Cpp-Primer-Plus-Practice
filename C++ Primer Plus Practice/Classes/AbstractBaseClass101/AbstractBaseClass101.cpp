//
//  AbstractBaseClass101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 03/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <string>
#include "BrassAccount02.hpp"

const int clients = 3;

void showAbstractBaseClass101()
{
    using AbstractBaseClass101::Account;
    using AbstractBaseClass101::Brass;
    using AbstractBaseClass101::BrassPlus;
    
    Account* p_clients[clients];              // array of pointers to abstract base class
    std::string tmpName;
    long tmpNumber;
    double tmpBalance;
    char kind;
    
    for (int i = 0; i < clients; i++)
    {
        std::cout << "Enter client's name: ";
        std::getline(std::cin, tmpName);
        
        std::cout << "Enter client's account number: ";
        std::cin >> tmpNumber;
        
        std::cout << "Enter opening balance: $";
        std::cin >> tmpBalance;
        
        std::cout << "Enter 1 for Brass Account and 2 for Brass Plus Account: ";
        
        while (std::cin >> kind && (kind != '1' && kind != '2'))
            std::cout << "Enter either 1 or 2: ";
        
        if (kind == '1')
            p_clients[i] = new Brass(tmpName, tmpNumber, tmpBalance);
        else
        {
            double tmpMax, tmpRate;
            std::cout << "Enter the overdraft limit: $";
            std::cin >> tmpMax;
            
            std::cout << "Enter the interest rate as a decimal fraction: ";
            std::cin >> tmpRate;
            
            p_clients[i] = new BrassPlus(tmpName, tmpNumber, tmpBalance, tmpMax, tmpRate);
        }
        
        while (std::cin.get() != '\n')      // clean up
            continue;
        
        std::cout << "\n";
    }
    
    for (int i = 0; i < clients; i++)       // polymorphic access
    {
        p_clients[i]->viewAccount();        // method is chosen based on the pointed-to object type
                                            // note: this choice can't be made at compile time
                                            //     - dynamic binding
        std::cout << "\n";
    }
    
    p_clients[0]->withdraw(100);
    p_clients[0]->viewAccount();
    
    for (int i = 0; i < clients; i++)
        delete p_clients[i];                // free memory: if destructor is not virtual, only
                                            //     the destructor for the pointer type is called
    
    std::cout << "\nDone.\n";
}
