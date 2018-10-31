//
//  FuncArray201.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 02/10/2018.
//

#include <iostream>

constexpr int Rows {3};
constexpr int Cols {4};

void print2Darray(int (*array)[Cols], int rows);    // equivalent to ...(int array[][Cols], ...)

void showFuncArray201()
{
    int array[Rows][Cols]
    {
        {0x10, 0x11, 0x12, 0x13},
        {0x14, 0x15, 0x16, 0x17},
        {0x18, 0x19, 0x1A, 0x1B}
    };
    print2Darray(array, Rows);
}

void print2Darray(int (*array)[Cols], int rows)
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < Cols; ++c)
            std::cout << array[r][c] << " ";
        std::cout << "\n";
    }
}
