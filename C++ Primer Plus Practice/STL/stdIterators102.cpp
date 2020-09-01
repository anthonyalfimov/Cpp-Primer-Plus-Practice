//
//  STLIterators102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 25/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// std::copy and insert iterators
//==================================================================================================

#include <iostream>
#include <string>
#include <iterator>
#include <vector>

void showStdIterators102()
{
    std::string alpha[4] { "fine", "fish", "fashion", "fate" };
    std::string beta[2] { "busy", "bats" };
    std::string gamma[2] { "silly", "singers" };
    
    std::vector<std::string> words (4);
    
    std::copy (&alpha[0], &alpha[4], words.begin());
    
    for (const auto& word : words)
        std::cout << word << " ";
    
    std::cout << "\n\n";
    
    // construct anonymous back_insert_iterator object to insert at the end of the vector
    using BackInsertIterator = std::back_insert_iterator<std::vector<std::string>>;
    std::copy (&beta[0], &beta[2], BackInsertIterator (words));
    
    for (const auto& word : words)
        std::cout << word << " ";
    
    std::cout << "\n\n";
    
    // construct anonymous insert_iterator object to insert at the front of the vector
    using InsertIterator = std::insert_iterator<std::vector<std::string>>;
    std::copy (&gamma[0], &gamma[2], InsertIterator (words, words.begin()));
    
    for (const auto& word : words)
        std::cout << word << " ";
    
    std::cout << "\n\nDone.\n";
}
