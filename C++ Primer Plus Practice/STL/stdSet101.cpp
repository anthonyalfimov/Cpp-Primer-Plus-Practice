//
//  StlSet101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 01/09/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// std::set
//==================================================================================================

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

void showStdSet101()
{
    std::set<std::string> alpha { "buffoon", "thinkers", "for", "heavy", "can", "for" };
    std::set<std::string> beta { "metal", "any", "food", "elegant", "deliver", "for" };
    
    std::ostream_iterator<std::string> output (std::cout, " ");
    
    std::cout << "Set Alpha: ";
    std::copy (alpha.cbegin(), alpha.cend(), output);    // set iterator is always constant, showing intent only
    
    std::cout << "\nSet Beta: ";
    std::copy (beta.cbegin(), beta.cend(), output);
    
    std::cout << "\n\nUnion of Alpha and Beta:\n";
    std::set_union (alpha.cbegin(), alpha.cend(), beta.cbegin(), beta.cend(), output);
    
    std::cout << "\n\nIntersection of Alpha and Beta:\n";
    std::set_intersection (alpha.cbegin(), alpha.cend(), beta.cbegin(), beta.cend(), output);
    
    std::cout << "\n\nDifference of Alpha and Beta:\n";
    std::set_difference (alpha.cbegin(), alpha.cend(), beta.cbegin(), beta.cend(), output);
    
    std::cout << "\n\nSet Gamma:\n";
    std::set<std::string> gamma;
    std::set_union (alpha.cbegin(), alpha.cend(), beta.cbegin(), beta.cend(),
                   std::insert_iterator<std::set<std::string>> (gamma, gamma.begin()));     // use anonymous insert iterator
    std::copy (gamma.cbegin(), gamma.cend(), output);
    
    std::cout << "\n\nSet Gamma after insertion:\n";
    std::string item ("grungy");
    gamma.insert (item);
    std::copy (gamma.cbegin(), gamma.cend(), output);
    
    std::cout << "\n\nShowing a range:\n";
    std::copy (gamma.lower_bound("ghost"), gamma.upper_bound("spook"), output);
    std::cout << "\n\nDone.\n";
}
