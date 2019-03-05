//
//  UseBaseClass01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "BaseClass01.hpp"

namespace
{
    void printTableStatus(const Inheritance101::TableTennisPlayer& p);
}

void showUseBaseClass01()
{
    using Inheritance101::TableTennisPlayer;
    
    TableTennisPlayer player1("Chuck", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    
    player1.Name();
    printTableStatus(player1);
    
    player2.Name();
    printTableStatus(player2);
    
}

namespace
{
    void printTableStatus(const Inheritance101::TableTennisPlayer& p)
    {
        if (p.hasTable())
            std::cout << ": has a table.\n";
        else
            std::cout << ": hasn't a table.\n";
    }
}
