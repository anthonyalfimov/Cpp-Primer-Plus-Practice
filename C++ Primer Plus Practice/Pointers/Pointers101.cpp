//
//  Pointers101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 30/07/2018.
//

#include <iostream>

void showPointers101()
{
    int updates {6};
    int * p_updates;
    p_updates = &updates;       // pointer assignment
    
    // express value in two ways
    std::cout << "Values: updates = " << updates
              << ", *p_updates = " << *p_updates << "\n";
    
    // express address in two ways
    std::cout << "Addresses: &updates = " << &updates
              << ", p_updates = " << p_updates << "\n";
    
    // use pointer to change value
    *p_updates += 1;
    std::cout << "Now updates is " << updates << "\n";
    
    int higgens {5};
    int * pt {&higgens};        // pointer initialization
    
    std::cout << "Value of higgens = " << higgens
              << "; Address of higgens = " << &higgens << "\n"
              << "Value of *pt = " << *pt
              << "; Value of pt = " << pt << "\n";
    
}
