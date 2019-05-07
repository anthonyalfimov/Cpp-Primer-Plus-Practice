//
//  ClassTemplates202.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 07/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Example of multiple template type parameters in a template class
//

#include <iostream>
#include <string>
#include "PairType01.hpp"

void showClassTemplates202()
{
    using ClassTemplates202::Pair;
    
    Pair<std::string, int> ratings[4]
    {
        {"The Purpled Duck", 5},
        {"Jaquie's Frisco Al Fresco", 4},
        {"Cafe Souffle", 5},
        {"Bertie's Eats", 3}
    };
    
    int joints = sizeof(ratings) / sizeof(Pair<std::string, int>);
    std::cout << "Rating\tEatery\n";
    
    for (int i = 0; i < joints; i++)
        std::cout << ratings[i].second() << ":\t\t" << ratings[i].first() << "\n";
    
    std::cout << "Oops! Revised rating:\n";
    ratings[3].first() = "Bertie's Fab Eats";
    ratings[3].second() = 6;
    std::cout << ratings[3].second() << ":\t\t" << ratings[3].first() << "\n";
}
