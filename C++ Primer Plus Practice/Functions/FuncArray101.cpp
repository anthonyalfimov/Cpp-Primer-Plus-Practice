//
//  FuncArray101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/10/2018.
//

#include <iostream>

const int ArSize {8};

/**
 Returns the sum of all elements in an int array

 @param array array pointer
 @param size size of the array
 @return sum of array elements
 */
int sumArray(const int array[], int size);    // 'int array[]' is equivalent to 'int* array'

void showFuncArray101()
{
    int cookies[ArSize] {1, 2, 4, 8, 16, 32, 64, 128};
    std::cout << cookies << " = array address,\t"
    << sizeof(cookies) << " = sizeof cookies\n";
    
    int sum {sumArray(cookies, ArSize)};
    std::cout << "Total cookies eaten: " << sum << "\n";
    
    sum = sumArray(cookies, 3);
    std::cout << "First three eaters ate " << sum << " cookies.\n";
    
    sum = sumArray(cookies + 4, 4);
    std::cout << "Last four eaters are " << sum << " cookies.\n";
}

int sumArray(const int arr[], int n)
{
    int total {};
//    std::cout << arr << " = arr address,\t"
//              << sizeof(arr) << " = sizeof arr\n\n";
    for (int i = 0; i < n; ++i)
        total += arr[i];
    return total;
}

