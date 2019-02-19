//
//  DynamicClasses202.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 19/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstdlib>              // for rand(), srand()
#include <ctime>                // for time()

#include "StringType01.hpp"

constexpr int Size = 10;
constexpr int MaxLength = 81;

void showDynamicClasses202()
{
    using DynamicClasses200::String;
    
    String name;
    std::cout << "Hi, what is your name?\n>> ";
    std::cin >> name;
    
    std::cout << name << ", please enter up to " << Size
              << " short sayings <empty line to quit>:\n";
    
    String sayings[Size];
    char temp[MaxLength];               // temporary string storage
    
    int i;
    for (i = 0; i < Size; i++)
    {
        std::cout << i + 1 << ": ";
        std::cin.get(temp, MaxLength);
        
        if (!std::cin)
            break;                      // on empty line, quit the loop
        else
            sayings[i] = temp;          // use overloaded assignment
        
        while (std::cin.get() != '\n')
            continue;                   // flush trailing characters if any
    }
    
    int total = i;
    
    if (total > 0)
    {
        std::cout << "Here are your sayings:\n";
        for (i = 0; i < total; i++)
            std::cout << sayings[i] << "\n";
        
        // Use pointers to keep track of shortest and first strings
        String* shortest = &sayings[0]; // initialise to the first object
        String* first    = &sayings[0];
        
        for (i = 1; i < total; i++)
        {
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first)
                first = &sayings[i];
        }
        
        std::cout << "Shortest saying:\n" << *shortest << "\n";
        std::cout << "First alphabetically:\n" << *first << "\n";
        
        // Randomly choose one saying
        std::srand(static_cast<int>(std::time(nullptr)));   // seed the random generation
        int choice = std::rand() % total;                   // pick index at random
        
        // Create and initialise a new object
        String* favourite = new String(sayings[choice]);
        std::cout << "My favourite saying:\n" << *favourite << "\n";
        delete favourite;
    }
    else
        std::cout << "No data to process, terminating.\n";
    
    std::cout << "\nDone.\n";
}
