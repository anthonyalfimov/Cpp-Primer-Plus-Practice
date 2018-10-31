//
//  Arrays201.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 02/10/2018.
//

#include <iostream>

constexpr int Rows {3};
constexpr int Cols {4};

void showArrays201()
{
    int array[Rows][Cols]
    {
        {0x10, 0x11, 0x12, 0x13},
        {0x14, 0x15, 0x16, 0x17},
        {0x18, 0x19, 0x1A, 0x1B}
    };
    
    std::cout << "\nArray address study:\n";
    std::cout
        << "&array       = " << &array << "\n"
        << "array        = " << array << ",\tsize = " << sizeof(array) << "\n"
        << "array[0]     = " << array[0] << ",\tsize = " << sizeof(array[0]) << "\n"
        << "array[1]     = " << array[1] << ",\tsize = " << sizeof(array[1]) << "\n"
        << "&array[0][0] = " << &array[0][0] << "\n";
    
}
