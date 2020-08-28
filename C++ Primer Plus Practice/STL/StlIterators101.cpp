//
//  STLIterators101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 25/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// iterators, std::copy, reverse_iterator and ostream_iterator
//==================================================================================================

#include <iostream>
#include <iterator>
#include <vector>

void showStlIterators101()
{
    constexpr int size = 10;
    int casts[size] { 6, 7, 2, 9, 4, 11, 8, 7, 10, 5 };
    std::vector<int> dice (10);
    
    // copy from array to vector
    std::copy (&casts[0], &casts[size], dice.begin());
    std::cout << "Let the dice be cast!\n";
    
    // create an ostream iterator
    std::ostream_iterator<int, char> outputIter (std::cout, " ");   // char template argument is optional
    
    // copy from vector to ouput
    std::copy (dice.begin(), dice.end(), outputIter);
    std::cout << "\n\n";
    
    std::cout << "Implicit use of reverse iterator:\n";
    std::copy (dice.rbegin(), dice.rend(), outputIter);
    std::cout << "\n\n";
    
    std::cout << "Explicit use of reverse iterator:\n";
    
    // incrementing a reverse iterator decrements it
    for (std::vector<int>::reverse_iterator rit = dice.rbegin(); rit != dice.rend(); ++rit)
        std::cout << *rit << " ";
    
    std::cout << "\n\nDone.\n";
}
