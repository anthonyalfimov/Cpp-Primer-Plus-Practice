//
//  BitFields101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 23/07/2018.
//

#include <iostream>

void showBitFields101()
{
    // NB! Bit field implementation is highly platform-dependent
    // (incl. allocaion in memory) and is NOT PORTABLE.
    // Bit fields also tend to be less perfpormant
    //
    // The portable and usually more performant solution is using
    // int type with bitwise operations
    
    struct test_register
    {
        unsigned int SN : 4;    // bit field of 4 bits
        unsigned int : 2;       // unused 4 bits for spacing
        bool goodInput : 1;
        bool goodTest : 1;
    };
    
    test_register tr {15, true, true};
    std::cout << "Register " << tr.SN << " input code " << tr.goodInput
              << ", test code " << tr.goodTest << "\n";
}
