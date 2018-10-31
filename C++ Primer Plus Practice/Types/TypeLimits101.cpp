//
//  TypeLimits.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 06/07/2018.
//

#include <iostream>
#include <climits>

void showTypeLimits101()
{
    std::cout << "Bits per byte: " << CHAR_BIT << "\n\n";
    std::cout << "Byte sizes of types:\n";
    std::cout << "int       is " << sizeof(int) << " bytes\n";
    std::cout << "short     is " << sizeof(short) << " bytes\n";
    std::cout << "long      is " << sizeof(long) << " bytes\n";
    std::cout << "long long is " << sizeof(long long) << " bytes\n";
    
    std::cout << "\nMaximum values:\n";
    std::cout << "int:       " << INT_MAX << " \n";
    std::cout << "short:     " << SHRT_MAX << " \n";
    std::cout << "long:      " << LONG_MAX << " \n";
    std::cout << "long long: " << LLONG_MAX << " \n";
    
    std::cout << "\nMinimum int value: " << INT_MIN << "\n";
    std::cout << "uint:      " << UINT_MAX << " \n";
}
