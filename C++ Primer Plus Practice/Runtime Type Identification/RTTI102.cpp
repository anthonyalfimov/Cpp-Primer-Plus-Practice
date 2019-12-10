//
//  RTTI102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 10/12/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstdlib>      // for rand(), srand()
#include <ctime>        // for time()
#include <typeinfo>     // for type_info class
#include "RTTI100.hpp"

void showRTTI102()
{
    using namespace RTTI100;
    
    std::srand (static_cast<unsigned> (std::time (nullptr)));   // seed the random number generator
    
    Grand* grandPtr;
    Superb* superbPtr;
    
    for (int i = 0; i < 5; ++i)
    {
        grandPtr = newRandomObject();   // create object - NB! Needs manual destruction!
        std::cout << "Now processing type " << typeid (*grandPtr).name() << ".\n";  // get type name
        grandPtr->speak();
        superbPtr = dynamic_cast<Superb*> (grandPtr);
        
        if (superbPtr != nullptr)
            superbPtr->say();
        
        if (typeid (Magnificent) == typeid (*grandPtr))         // perform type-dependent action that is not a method
            std::cout << "Yes, you are truly magnificent!\n";
        
        std::cout << "\n";
        delete grandPtr;                // destroy object
    }
}
