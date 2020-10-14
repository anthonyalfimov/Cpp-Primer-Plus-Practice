//
//  STLandValarray102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 14/10/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// Exploring valarray slicing capabilities
//==================================================================================================

#include <iostream>
#include <valarray>
#include <cstdlib>
#include <ctime>

namespace
{
    using vint = std::valarray<int>;

    void printGrid (const vint& dataArray, int columns);
}

void showSTLandValarray102()
{
    const int size = 12;
    vint data (size);
    std::srand (static_cast<unsigned> (std::time (nullptr)));
    
    for (int& item : data)      // std::begin() and std::end() allow using range-based for loops
        item = std::rand() % 10;
    
    std::cout << "Original array:\n";
    printGrid (data, 3);        // print in 3 columns
    
    using std::slice;
    vint secondColumn (data[slice (1, 4, 3)]);   // extract 2nd column
    std::cout << "\nSecond column:\n";
    printGrid (secondColumn, 1);    // print in 1 column
    
    vint secondRow (data[slice (3, 3, 1)]);      // extract 2nd row
    std::cout << "\nSecond row:\n";
    printGrid (secondRow, 3);
    
    data[slice (2, 4, 3)] = 10; // set 3rd column values to 10
    std::cout << "\nSet last column to 10:\n";
    printGrid (data, 3);
    
    // operator+() is not defined for slices, so construct anonymous std::valarray<int> objects
    data[slice (0, 4, 3)] = vint (data[slice (1, 4, 3)]) + vint (data[slice (2, 4, 3)]);
    std::cout << "\nSet first column to sum of next two:\n";
    printGrid (data, 3);
    
    std::cout << "\nDone.\n";
}

namespace
{
    void printGrid (const vint& dataArray, int columns)
    {
        const auto limit = dataArray.size();
        
        for (int i = 0; i < limit; ++i)
        {
            std::cout.width (3);
            std::cout << dataArray[i];
            
            if (i % columns == columns - 1)
                std::cout << "\n";
            else
                std::cout << " ";
        }
        
        if (limit % columns != 0)
            std::cout << "\n";
    }
}
