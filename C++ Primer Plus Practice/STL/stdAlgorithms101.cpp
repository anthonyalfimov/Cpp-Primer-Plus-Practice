//
//  stdAlgorithms101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 06/10/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// STL Algorithms as methods and non-member functions
//==================================================================================================

#include <iostream>
#include <list>
#include <algorithm>

void showStdAlgorithm101()
{
    std::list<int> alpha { 4, 5, 4, 2, 2, 3, 4, 8, 1, 4 };
    std::list<int> beta (alpha);
    
    std::cout << "Original list contents:\n\t\t";
    
    // Declare a local-scope named lambda
    auto show = [] (int value) { std::cout << value << " "; };
    std::for_each (alpha.cbegin(), alpha.cend(), show);
    
    // Remove all values of 4; containter method will resize the container
    alpha.remove (4);
    std::cout << "\n\nAfter using the remove() method:\nalpha\t";
    std::for_each(alpha.cbegin(), alpha.cend(), show);
    
    // Remove all values of 4; non-member function places these values in the end of the list
    //  and returns an iterator one-past the 'good' range
    std::list<int>::iterator betaLast = std::remove (beta.begin(), beta.end(), 4);
    std::cout << "\n\nAfter usign the remove() non-member function:\nbeta\t";
    std::for_each (beta.cbegin(), beta.cend(), show);
    
    // Clean up 'bad' values at the end of the beta list
    beta.erase (betaLast, beta.end());
    std::cout << "\n\nAfter using the erase() method:\nbeta\t";
    std::for_each(beta.cbegin(), beta.cend(), show);
    
    std::cout << "\n\nDone.\n";
}
