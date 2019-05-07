//
//  ClassTemplates201.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 07/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Example of recursive use for class template
//

#include <iostream>
#include "ArrayType01.hpp"

constexpr int cols = 5;
constexpr int rows = 10;

void showClassTemplates201()
{
    using ClassTemplates201::Array;
    
    Array<int, rows> sums;
    Array<double, rows> averages;
    Array<Array<int, cols>, rows> matrix;        // 2D array
    int i, j;
    
    for (i = 0; i < rows; i++)
    {
        sums[i] = 0;
        
        for (j = 0; j < cols; j++)
        {
            matrix[i][j] = (i + 1) * (j + 1);   // fill the matrix
            sums[i] += matrix[i][j];            // add to row sum
        }
        
        averages[i] = double(sums[i]) / cols;   // calculate row average
    }
    
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            std::cout.width(2);                 // display next item tiwh field width of two chars
            std::cout << matrix[i][j] << ' ';
        }
        
        std::cout << ": sum = ";
        std::cout.width(3);                     // display next item tiwh field width of three chars
        std::cout << sums[i] << ", average = " << averages[i] << "\n";
    }
    
    std::cout << "\nDone.\n";
}
