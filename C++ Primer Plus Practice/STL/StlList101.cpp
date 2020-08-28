//
//  StlList101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 28/08/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// std::list
//==================================================================================================

#include <iostream>
#include <list>
#include <algorithm>

namespace
{
    void printInt (int n) { std::cout << n << " "; }
}

void showStlList101()
{
    std::list<int> alpha (5, 2);    // list of five 2s
    
    std::list<int> beta {1, 2, 4, 8, 6};
    
    std::list<int> gamma (beta);
    int data[6] {6, 4, 2, 4, 6, 5};
    gamma.insert (gamma.end(), &data[0], &data[6]);
    
    // Print three lists
    std::cout << "List Alpha: ";
    std::for_each(alpha.begin(), alpha.end(), printInt);
    
    std::cout << "\nList Beta: ";
    std::for_each(beta.begin(), beta.end(), printInt);
    
    std::cout << "\nList Gamma: ";
    std::for_each(gamma.begin(), gamma.end(), printInt);
    
    // Remove 2s from list gamma
    gamma.remove(2);
    std::cout << "\nList Gamma without 2s: ";
    std::for_each(gamma.begin(), gamma.end(), printInt);
    
    // Splice list alpha into the begginning of list gamma
    gamma.splice(gamma.begin(), alpha);
    std::cout << "\nList Gamma after splice: ";
    std::for_each(gamma.begin(), gamma.end(), printInt);
    std::cout << "\nList Alpha after splice: ";
    std::for_each(alpha.begin(), alpha.end(), printInt);
    
    // Remove consecutive equal elements from gamma
    gamma.unique();
    std::cout << "\nList Gamma after unique: ";
    std::for_each(gamma.begin(), gamma.end(), printInt);
    
    gamma.sort();   // non-member sort requires random access, so can't be used with std::list
    gamma.unique();
    std::cout << "\nList Gamma after sort and unique: ";
    std::for_each(gamma.begin(), gamma.end(), printInt);
    
    // Sort list beta and merge with gamma
    beta.sort();
    gamma.merge(beta);
    std::cout << "\nList Gamma after merging with sorted beta: ";
    std::for_each(gamma.begin(), gamma.end(), printInt);
    
    std::cout << "\n\nDone.\n";
}
