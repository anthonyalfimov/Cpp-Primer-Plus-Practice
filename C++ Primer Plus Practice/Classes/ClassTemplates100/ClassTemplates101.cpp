//
//  ClassTemplates101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 06/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include "StackType02.hpp"

namespace
{
    void clearInputBuffer() { while (std::cin.get() != '\n') continue; }
}

void showClassTemplates101()
{
    using namespace ClassTemplates101;
    
    Stack<std::string> st;                  // create an empty stack
    char ch;
    std::string entry;
    std::cout << "Please enter A to add a purchase to order,\n"
                 "P to process a PO, or Q to quit.\n";
    
    while (std::cin >> ch && (ch = std::toupper(ch)) != 'Q')
    {
        clearInputBuffer();
        
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
