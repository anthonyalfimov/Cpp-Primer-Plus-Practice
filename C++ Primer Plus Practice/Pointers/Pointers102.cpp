//
//  Pointers102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 31/07/2018.
//

#include <iostream>

void showPointers102()
{
    int nights {1001};
    int * pt {new int};     // allocate memory for an int
    *pt = 1001;             // store a value there
    
    std::cout << "nights value = " << nights << ": location (stack): " << &nights << "\n"    // returns stack address
              << "int value " << *pt << ": location (heap): " << pt << "\n";                 // returns heap address
    
    double * pd {new double};   // allocate space for a double
    *pd = 10000001.0;           //store a double there
    
    std::cout << "double value " << *pd << ": location (heap): " << pd << "\n"               // returns heap address
              << "location of pointer pd (stack): " << &pd << "\n"                           // returns stack address
              << "size of pt = " << sizeof(pt) << ": size of *pt = " << sizeof(*pt) << "\n"
              << "size of pd = " << sizeof(pd) << ": size of *pd = " << sizeof(*pd) << "\n";
    
    delete pt;      // free allocated memory
    delete pd;
}
