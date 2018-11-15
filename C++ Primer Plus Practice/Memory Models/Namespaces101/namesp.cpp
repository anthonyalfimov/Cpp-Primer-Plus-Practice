//
//  namesp.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 15/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "namesp.hpp"

namespace pers
{
    using std::cout;
    using std::cin;
    
    void getPerson(Person& refPerson)
    {
        cout << "Enter first name: ";
        cin >> refPerson.fname;
        cout << "Enter last name: ";
        cin >> refPerson.lname;
    }
    
    void showPerson(const Person& refPerson)
    {
        std::cout << refPerson.lname << ", " << refPerson.fname;
    }
}

namespace debts
{
    void getDebt(Debt& refDebt)
    {
        getPerson(refDebt.name);
        std::cout << "Enter debt: ";
        std::cin >> refDebt.amount;
    }
    
    void showDebt(const Debt& refDebt)
    {
        showPerson(refDebt.name);
        std::cout << ": $" << refDebt.amount << "\n";
    }
    
    double sumDebts(const Debt debts[], int size)
    {
        double total {};
        for (int i = 0; i < size; i++)
            total += debts[i].amount;
        return total;
    }
}
