//
//  functionObjects101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 15/09/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// Function Object (functor) concept
//==================================================================================================

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

namespace
{
    // Function Object model class defines operator() ()

    template <typename Type>
    class ExceedsThreashold
    {
    public:
        ExceedsThreashold (const Type& threashold) : mThreashold (threashold) {}
        bool operator() (const Type& value) { return value > mThreashold; }
        
    private:
        Type mThreashold;
    };
}

void showFunctionObjects101()
{
    ExceedsThreashold<int> isGreaterThan100 (100);
    
    std::list<int> alpha { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
    std::list<int> beta (alpha);
    
    std::cout << "Original lists:\n";
    
    for (const auto& value : alpha)
        std::cout << value << " ";
    
    std::cout << "\n";
    
    for (const auto& value : beta)
        std::cout << value << " ";
    
    std::cout << "\n";
    
    alpha.remove_if (isGreaterThan100);                 // use a named function object
    beta.remove_if (ExceedsThreashold<int> (200));      // use a temporary function object
    
    std::cout << "\nTrimmed lists:\n";
    
    for (const auto& value : alpha)
        std::cout << value << " ";
    
    std::cout << "\n";
    
    for (const auto& value : beta)
        std::cout << value << " ";
    
    std::cout << "\n\nDone.\n";
}
