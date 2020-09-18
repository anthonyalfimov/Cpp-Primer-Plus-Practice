//
//  functionBinders101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 18/09/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// STL Function Objects and Function Binders (!Deprecated! - Use lambdas instead)
//==================================================================================================

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

namespace
{
    void show (double a)
    {
        std::cout.width (6);
        std::cout << a << ' ';
    }
}

void showFunctionObjects102()
{
    std::vector<double> alpha {28, 29, 30, 35, 38, 59};
    std::vector<double> beta  {63, 65, 69, 75, 80, 99};
    
    // Set formatting to fixed 1 decimal sign
    std::cout.setf (std::ios_base::fixed);
    std::cout.precision (1);
    
    std::cout << "alpha:\t";
    std::for_each(alpha.cbegin(), alpha.cend(), show);
    std::cout << "\nbeta:\t";
    std::for_each(beta.cbegin(), beta.cend(), show);
    
    std::vector<double> sum;
    using BackInsertIterator = std::back_insert_iterator<std::vector<double>>;
    
    // Use pre-defined STL function object `plus` with a binary version of `transform`
    std::transform (alpha.cbegin(), alpha.cend(), beta.cbegin(),
                    BackInsertIterator (sum), std::plus<double>());
    
    std::cout << "\nsum:\t";
    std::for_each(sum.cbegin(), sum.cend(), show);
    
    std::vector<double> product;
    
    // Use deprecated STL binder to adapt function object `multiplies` from binary to unary
    //  and use it with an unary version of `transform`
    
//    std::transform (alpha.cbegin(), alpha.cend(),
//                    BackInsertIterator (product), std::bind1st(std::multiplies<double>(), 2.5));
    
    // Use a lambda expression with an unary version of `transform`
    std::transform(alpha.cbegin(), alpha.cend(),
                   BackInsertIterator (product), [](double x) { return x * 2.5; });
    
    std::cout << "\nprod:\t";
    std::for_each(product.cbegin(), product.cend(), show);
    
    std::cout << "\n\nDone.\n";
}
