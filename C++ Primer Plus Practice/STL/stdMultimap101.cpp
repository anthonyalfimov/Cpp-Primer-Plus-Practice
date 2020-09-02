//
//  stdMultimap101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 02/09/2020.
//  Copyright © 2020 Anthony. All rights reserved.
//

//==================================================================================================
// std::multimap
//==================================================================================================

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

void showStdMultimap101()
{
    using KeyType = int;
    using Pair = std::pair<const KeyType, std::string>;
    using CityCodeMap = std::multimap<KeyType, std::string>;
    
    CityCodeMap codes;
    
    codes.insert (Pair (415, "San Franciso"));
    codes.insert (Pair (510, "Oakland"));
    codes.insert (Pair (718, "Brooklyn"));
    codes.insert (Pair (718, "Staten Island"));
    codes.insert (Pair (415, "San Rafael"));
    codes.insert (Pair (510, "Berkeley"));
    
    std::cout
        << "Number of cities with area code 415: "
        << codes.count (415) << "\n"
        << "Number of cities with area code 718: "
        << codes.count (718) << "\n"
        << "Number of cities with area code 510: "
        << codes.count (510) << "\n";
    
    std::cout << "\nArea code\tCity\n";
    
    for (const Pair& item : codes)      // can use auto instead
        std::cout << "\t  " << item.first << "\t" << item.second << "\n";
    
//  Old way of using iterators:
//    for (CityCodeMap::const_iterator it = codes.cbegin(); it != codes.cend(); ++it)
//        std::cout << "\t  " << it->first << "\t" << it->second << "\n";
    
//  const overload of equal_range is only used if the object is const
    std::pair<CityCodeMap::iterator, CityCodeMap::iterator> range = codes.equal_range (718);
    std::cout << "\nCities with area code 718:\n";
    
    for (CityCodeMap::iterator it = range.first; it != range.second; ++it)
        std::cout << it->second << "\n";
    
//  Keeping the iterators const with auto in C++17:
//    auto range = std::as_const(codes).equal_range (718);
//    std::cout << "\nCities with area code 718:\n";
//
//    for (CityCodeMap::const_iterator it = range.first; it != range.second; ++it)
//        std::cout << it->second << "\n";
    
    std::cout << "\nDone.\n";
}
