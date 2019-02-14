//
//  DynamicClasses201.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 14/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "StringType01.hpp"

constexpr int Size = 10;
constexpr int MaxLength = 81;

void showDynamicClasses201()
{
    using DynamicClasses201::String;
    
    String name;
    std::cout << "Hi, what is your name?\n>> ";
    std::cin >> name;
    
    std::cout << name << ", please enter up to " << Size
              << " short saygings <empty line to quit>:\n";
    
    String sayings[Size];           // array of objects
    char temp[MaxLength];           // temporary storage
    int i;                          // iterator
    
    // Use temporary char array for input to demonstrate the use of the overloaded assignment
    //     operator for C-strings
    for (i = 0; i < Size; i++)
    {
        std::cout << i + 1 << ": ";
        std::cin.get(temp, MaxLength);
        while (std::cin && std::cin.get() != '\n')      // flush leftover characters if any
            continue;
        
        if (!std::cin)              // if input failed -- empty line
            break;                  // break the loop, i not incremented
        else
            sayings[i] = temp;      // use overloaded assignement operator
    }
    
    int total = i;                  // total number of lines
    
    if (total > 0)
    {
        std::cout << "Here are your sayings:\n";
        // Use the element access operator overload here:
        for (i = 0; i < total; i++)
            std::cout << sayings[i][0] << ": " << sayings[i] << "\n";
        
        int shortest = 0;
        int first = 0;
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < sayings[shortest].length())
                shortest = i;
            if (sayings[i] < sayings[first])
                first = i;
        }
        
        std::cout << "Shortest saying:\n" << sayings[shortest] << "\n";
        std::cout << "First alphabetically:\n" << sayings[first] << "\n";
        std::cout << "This program used " << String::stringCount() << " String objects.\n";
    }
    else
        std::cout << "No input!\n";
    
    std::cout << "\nDone.\n";
}
