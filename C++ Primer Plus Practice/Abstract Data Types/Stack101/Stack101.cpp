//
//  Stack101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 29/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include <cctype>
#include "StackType01.hpp"

namespace
{
    void clearInputBuffer() { while (std::cin.get() != '\n') continue; }
}

void showStack101()
{
    using namespace Stack01;
    
    Stack st;               // create an empty stack
    char ch;
    unsigned long entry;
    
    std::cout << "Please enter A to add a purchase to order,\n"
                 "P to process a PO, or Q to quit.\n";
    while (std::cin >> ch && (ch = std::toupper(ch)) != 'Q')
    {
        clearInputBuffer();       // clear the rest of the input buffer
        if (!std::isalpha(ch))
        {
            std::cout << "Invalid input!\n";
            continue;
        }
        switch (ch)
        {
            case 'A':
                if (st.isFull())
                    std::cout << "Stack already full\n";
                else
                {
                    std::cout << "Enter a PO number to add: ";
                    
                    while (!(std::cin >> entry))
                    {
                        std::cout << "Invalid input!\n";
                        std::cin.clear();
                        clearInputBuffer();
                    }
                    clearInputBuffer();
                    st.push(entry);
                }
                break;
            
            case 'P':
                if (st.isEmpty())
                    std::cout << "Stack already empty\n";
                else
                {
                    st.pop(entry);
                    std::cout << "PO #" << entry << " popped\n";
                }
        }
        
        std::cout << "Please enter A to add a purchase to order,\n"
                     "P to process a PO, or Q to quit.\n";
    }
    std::cout << "\nDone.\n";
}
