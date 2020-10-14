//
//  STLandValarray101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 14/10/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// Using the valarray library with STL facilities
//==================================================================================================

#include <iostream>
#include <valarray>
#include <vector>
#include <algorithm>

void showSTLandValarray101()
{
    std::vector<double> inputData;
    double inputItem;
    
    std::cout << "Enter numbers (<=0 to quit):\n";
    
    while (std::cin >> inputItem && inputItem > 0)
        inputData.push_back (inputItem);
    
    std::sort (inputData.begin(), inputData.end());
    const auto size = inputData.size();
    
    std::valarray<double> data (size);
    std::copy (inputData.cbegin(), inputData.cend(), std::begin (data));    // use STL interface
    
    std::valarray<double> squareRoots (size);
    squareRoots = sqrt (data);  // sqrt() is overloaded for valarray to be applied element-wise
    
    std::valarray<double> results (size);
    results = data + 2.0 * squareRoots;     // operators are overloaded to be applied element-wise
    
    std::cout.setf (std::ios_base::fixed);
    std::cout.precision (4);
    
    // Is there a good way to do this with iterators? Transfer data to a std::map?
    for (int i = 0; i < size; ++i)
    {
        std::cout.width (8);
        std::cout << data[i] << ": ";
        std::cout.width (8);
        std::cout << results[i] << "\n";
    }
    
    std::cout << "\nDone.\n";
}
