//
//  ExceedingLimits.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 06/07/2018.
//
//  exceeding integer limits
//

#include <iostream>
#include <climits>

#define ZERO 0

void printSamSueBalance(short sam, unsigned short sue)
{
    std::cout << "Sam has " << sam << " dollars and Sue has "
              << sue << " dollars deposited.\n";
}

void showTypeLimits102()
{
    // NOTE: using {} initialization for sue will give an error
    // due to narrowing type conversion
    // Explicit type cast must be used!
    //
    // This doesn't happen with () or = initialization
    
    short sam {SHRT_MAX};
    unsigned short sue {static_cast<unsigned short>(sam)};
    
    printSamSueBalance(sam, sue);
    std::cout << "Add $1 to each account.\n" "Now ";
    ++sam;
    ++sue;
    printSamSueBalance(sam, sue);
    std::cout << "Poor Sam!\n";
    
    sam = sue = ZERO;       // assignment operator applied serially, from right to left
    printSamSueBalance(sam, sue);
    std::cout << "Take $1 from each account.\n" "Now ";
    --sam;
    --sue;
    printSamSueBalance(sam, sue);
    std::cout << "Lucky Sue!\n";
}
