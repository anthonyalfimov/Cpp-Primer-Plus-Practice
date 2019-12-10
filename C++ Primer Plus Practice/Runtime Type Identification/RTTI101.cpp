//
//  RTTI101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 09/12/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstdlib>      // for rand(), srand()
#include <ctime>        // for time()
#include "RTTI100.hpp"

void showRTTI101()
{
    using namespace RTTI100;
    
    std::srand (static_cast<unsigned> (std::time (nullptr)));   // seed the random number generator
    
    Grand* grandPtr;
    Superb* superbPtr;
    
    for (int i = 0; i < 5; ++i)
    {
        grandPtr = newRandomObject();   // create object - NB! Needs manual destruction!
        grandPtr->speak();              // common method for all class hierarchy
        superbPtr = dynamic_cast<Superb*> (grandPtr);
        
        if (superbPtr != nullptr)
            superbPtr->say();           // method unique to Superb and Magnificent classes
        
        std::cout << "\n";
        delete grandPtr;                // destroy object
    }
}
