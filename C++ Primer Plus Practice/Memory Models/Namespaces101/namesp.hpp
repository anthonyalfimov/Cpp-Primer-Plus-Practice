//
//  namesp.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 15/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef namesp_hpp
#define namesp_hpp

#include <string>

namespace pers
{
    struct Person
    {
        std::string fname;
        std::string lname;
    };
    
    void getPerson(Person&);
    void showPerson(const Person&);
}

namespace debts
{
    using namespace pers;   // using directive
//  using pers::Person;     // using declaration
    
    struct Debt
    {
        Person name;
        double amount;
    };
    
    void getDebt(Debt&);
    void showDebt(const Debt&);
    double sumDebts(const Debt array[], int size);
}

#endif /* namesp_hpp */
