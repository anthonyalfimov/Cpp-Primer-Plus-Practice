//
//  Inheritance101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 20/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "DerivedClass01.hpp"

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

void showInheritance101()
{
    using Inheritance101::TableTennisPlayer;
    using Inheritance101::RatedPlayer;
    
    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    
    rplayer1.name();                // derived object uses base method
    printTableStatus(rplayer1);     // base-class reference can refer to a derived-class object
    
    player1.name();                 // base object uses base method
    printTableStatus(player1);
    
    std::cout << "\nName: ";
    rplayer1.name();
    std::cout << "; Rating: " << rplayer1.rating() << "\n";
    
    // Inintialise RatedPlayer object using TableTennisPlayer object
    RatedPlayer rplayer2(1230, player1);
    
    std::cout << "Name: ";
    rplayer2.name();
    std::cout << "; Rating: " << rplayer2.rating() << "\n";
    
    std::cout << "\nDone.\n";
}
