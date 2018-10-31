//
//  FuncArray103.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/10/2018.
//
//  ==================================================
//
//  This program demonstrates the range-based approach
//  to passing an array to a funcion
//
//  ==================================================

#include <iostream>

const int Size {8};

// Function protorype
/**
 Range-based sum of int array elements

 @param begin pointer to the beginning of the array
 @param end pointer to the one-past-the-end element of the array
 @return sum of the array elements
 */
int sumRangeArray(const int* begin, const int* end);

void showFuncArray103()
{
    int cookies[Size] {1, 2, 4, 8, 16, 32, 64, 128};
    int sum {sumRangeArray(cookies, cookies + Size)};
    std::cout << "Total cookies eaten: " << sum << ".\n";
    
    sum = sumRangeArray(cookies, cookies + 3);
    std::cout << "The first three eaters ate " << sum << " cookies.\n";
    
    sum = sumRangeArray(cookies + 4, cookies + Size);
    std::cout << "The last four eaters ate " << sum << " cookies.\n";
}

int sumRangeArray(const int* begin, const int* end)
{
    int total {};
    for (const int* pt = begin; pt != end; ++pt)
        total += *pt;
    
    return total;
}
