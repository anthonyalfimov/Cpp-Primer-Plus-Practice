//
//  ClassTemplates102.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 06/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <cstdlib>                      // for rand(), srand()
#include <ctime>                        // for time()
#include "StackType03.hpp"

constexpr int NUM = 10;

void showClassTemplates102()
{
    using ClassTemplates102::Stack;
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));     // seed rand()
    
    std::cout << "Please enter stack size: ";
    int stackSize;
    std::cin >> stackSize;
    
    // Plodson takes a file from a cart into his in-basket, if the latter is empty.
    // If the in-basket is full, he processes a file from it and puts it into the out-basket.
    // If the in-basket is neither full nor empty, he flips a coin and either takes another file
    //     from the cart, or processes one file from in-basket and puts it into the out-basket.
    
    // In basket
    Stack<const char*> inBasket(stackSize);    // create an empty stack with stackSize slots
    
    // Cart with documents to process
    const char* cart[NUM]
    {
        " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
        " 3: Betty Rocker", " 4: Ian Flagranti",
        " 5: Wolfgang Kibble", " 6: Portia Koop",
        " 7: Joy Almondo", " 8: Xaverie Paprika",
        " 9: Juan Moore", "10: Misha Mache"
    };
    
    // Out basket
    const char* outBasket[NUM];
    
    int processed = 0;
    int nextIn = 0;
    
    while (processed < NUM)
    {
        if (inBasket.isEmpty())
        {
            inBasket.push(cart[nextIn]);            // only address is pushed, strings never move!
            nextIn++;
        }
        else if (inBasket.isFull())
        {
            inBasket.pop(outBasket[processed]);     // only address is popped, strings never move!
            processed++;
        }
        else if (nextIn < NUM && std::rand() % 2)   // something's left in cart and 50-50 chance
        {
            inBasket.push(cart[nextIn]);
            nextIn++;
        }
        else
        {
            inBasket.pop(outBasket[processed]);
            processed++;
        }
    }
    
    for (int i = 0; i < NUM; i++)
        std::cout << outBasket[i] << "\n";
    
    std::cout << "\nDone.\n";
}
