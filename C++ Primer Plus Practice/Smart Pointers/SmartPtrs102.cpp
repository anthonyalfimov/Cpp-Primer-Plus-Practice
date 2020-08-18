//
//  SmartPtrs102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 18/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// Ownership transfer vs reference counting:
//  this code works with shared_ptr, but not auto_ptr (crash) or unique_ptr (compiler error)
//==================================================================================================

#include <iostream>
#include <string>
#include <memory>

void showSmartPtrs102()
{
    std::shared_ptr<std::string> films[5]
    {
        std::shared_ptr<std::string> (new std::string ("Fowl Balls")),
        std::shared_ptr<std::string> (new std::string ("Duck Walks")),
        std::shared_ptr<std::string> (new std::string ("Chicken Runs")),
        std::shared_ptr<std::string> (new std::string ("Turkey Errors")),
        std::shared_ptr<std::string> (new std::string ("Goose Eggs"))
    };
    
    std::shared_ptr<std::string> winner;
    winner = films[2];                  // films[2] looses ownership if using auto_ptr,
                                        // increas reference count if using shared_ptr
    
    std::cout << "The nominees for the best avian baseball fime are:\n";
    
    for (int i = 0; i < 5; ++i)
        std::cout << *films[i] << "\n";
    
    std::cout << "The winner is " << *winner << "!\n";
    std::cout << "\nDone.\n";
}
