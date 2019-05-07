//
//  ClassTemplates103.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 07/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Partial specialisation example
//

#include <iostream>
#include <cctype>
#include "StackType04.hpp"

const int SIZE = 40;

namespace
{
    void clearInputBuffer() { while (std::cin.get() != '\n') continue; }
}

void showClassTemplates103()
{
    using namespace ClassTemplates103;
    
    Stack<int, 0> nully;
    Stack<int, 10> another;
    Stack<char*> st;                    // create an empty C-string stack with default size
    std::cout << "\n";
    
    char ch;
    char entry[SIZE];                   // temp entry string
    
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
                    st.pop(entry, SIZE);
                    std::cout << "PO #" << entry << " popped\n";
                }
        }
        
        std::cout << "Please enter A to add a purchase to order,\n"
        "P to process a PO, or Q to quit.\n";
    }
    
    std::cout << "\nDone.\n";
}
