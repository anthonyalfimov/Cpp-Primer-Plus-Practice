//
//  Loops101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 17/08/2018.
//

#include <iostream>

void showLoops101()
{
    constexpr int size {20};
    char word[size];
    
    std::cout << "Enter a word: ";
    std::cin >> word;

    char* pc {word};

    for(int i = 0; *(pc + i); ++i)
        std::cout << pc[i];
    std::cout << "\n";
}
