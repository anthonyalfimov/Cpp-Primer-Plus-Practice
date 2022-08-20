//
//  initializerList101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 18/03/2021.
//  Copyright © 2021 Anthony. All rights reserved.
//

//==============================================================================
// Using the initializer_list template
//==============================================================================

#include <iostream>
#include <initializer_list>

namespace
{
    double sum (std::initializer_list<double> items);
    double average (const std::initializer_list<double>& items);
}

void showInitializerList101()
{
    // Values are implicitely converted to double as per the function parameter
    std::cout << "List 1: sum = " << sum ({2, 3, 4})
              << ", average = " << average ({2, 3, 4}) << "\n";
    
    std::initializer_list<double> list = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    std::cout << "List 2: sum = " << sum (list)
              << ", average = " << average (list) << "\n";
    
    list = {16.0, 25.0, 36.0, 40.0, 64.0};
    std::cout << "List 3: sum = " << sum (list)
              << ", average = " << average (list) << "\n";
}

namespace
{
    double sum (std::initializer_list<double> items)
    {
        double result = 0.0;
        
        // Iterators .begin() and .end() allow using range-based for loop
        for (auto item : items)
            result += item;
        
        return result;
    }
    
    double average (const std::initializer_list<double>& items)
    {
        double sum = 0.0;
        double result = 0.0;
        auto listSize = items.size();
        
        if (listSize <= 0)
            return result;
        
        // Using .begin() and .end() iterators explicitely
        for (auto p = items.begin(); p != items.end(); ++p)
            sum += *p;
        
        result = sum / listSize;
        
        return result;
    }
}
