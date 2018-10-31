//
//  DynamicArrays101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/08/2018.
//

#include <iostream>

void showDynamicArrays101()
{
    double * p3 { new double [3] {0.2, 0.5, 0.8} };     // allocate memory for 3 doubles, initialize using list
                                                        // note that brace initialization can be used for the pointer
                                                        // itself, although it doesn't look clear
    std::cout << "p3[1] is " << p3[1] << ".\n";
    ++p3;
    std::cout << "Now p3[0] is " << p3[0]
              << " and p3[1] is " << p3[1] << ".\n";
    --p3;                                               // return the pointer to the original address
    delete[] p3;
}
