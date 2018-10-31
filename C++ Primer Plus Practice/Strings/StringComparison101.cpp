//
//  StringComparison101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 21/08/2018.
//

#include <iostream>
#include <cstring>

// Comparing C-style strings

void showStringComparison101()
{
    const char * prototype {"mate"};        // this works because string literal is an address
    char word[5] {"?ate"};
    for (char ch = 'a'; std::strcmp(word, prototype); ++ch)
    {
        std::cout << word << "\n";
        word[0] = ch;
    }
    std::cout << "After the loop ends, the word is " << word << "\n";
}
