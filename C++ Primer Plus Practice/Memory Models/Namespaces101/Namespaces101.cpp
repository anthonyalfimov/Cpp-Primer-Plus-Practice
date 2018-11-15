//
//  Namespaces101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 15/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "namesp.hpp"

namespace
{
    void other();
    void another();
}

//   =============================
//   |       Main function       |
//   =============================
void showNamespaces101()
{
    using debts::Debt;              // Better approach: only import required names
    using debts::showDebt;
    
    Debt golf
    {
        {"Benny", "Goatsniff"},
        120.0
    };
    
    showDebt(golf);
    
    other();
    another();
}

namespace
{
    void other()
    {
        using std::cout;
        using std::endl;
        using namespace debts;      // Worse approach: import both entire namespaces
                                    // puts `debts` and `pers` namespaces in scope
                                    // due to `using` directive inside `debts` namespace
        
        Person dg {"Doodles", "Glister"};
        showPerson(dg);
        cout << endl;
        
        Debt zippy[3];
        int i;
        for (i = 0; i < 3; i++)
            getDebt(zippy[i]);
        
        for (i = 0; i < 3; i++)
            showDebt(zippy[i]);
        
        cout << "Total debt: $" << sumDebts(zippy, 3) << endl;
    }
    
    void another()
    {
        using pers::Person;
        Person collector {"Milo", "Rightshift"};
        pers::showPerson(collector);
        std::cout << std::endl;
    }
}
