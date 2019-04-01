//
//  Inheritance201.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 28/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Example in polymorphic public inheritance
//      - demonstate redefining base-class methods

#include <iostream>
#include "BrassAccount01.hpp"

void showInheritance201()
{
    using Inheritance200::Brass;
    using Inheritance200::BrassPlus;
    
    Brass piggy("Porcelot Pigg", 381299, 4000.0);
    BrassPlus hoggy("Horatio Hogg", 382288, 3000.0);
    
    piggy.viewAccount();
    std::cout << "\n";
    hoggy.viewAccount();
    std::cout << "\n";
    
    std::cout << "Depositing $1000 into the Hogg account:\n";
    hoggy.deposit(1000);
    std::cout << "New balance: $" << hoggy.balance() << "\n\n";
    
    std::cout << "Withdrawing $4200 form Pigg account:\n";
    piggy.withdraw(4200);
    std::cout << "Pigg account balance: $" << piggy.balance() << "\n\n";
    
    std::cout << "Withdrawing $4200 from the Hogg account:\n";
    hoggy.withdraw(4200);
    hoggy.viewAccount();
    
    std::cout << "\nDone.\n";
}
