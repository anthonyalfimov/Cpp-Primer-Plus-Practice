//
//  StringComparison102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 21/08/2018.
//

#include <iostream>
#include <string>

// Comparing string class objects

void showStringComparison102()
{
    const char * prototype {"mate"};        // this works because string literal is an address
    std::string word {"?ate"};
    for (char ch = 'a'; word != prototype; ++ch)    // string class overloads relational operators
                                                    // it can be used as long as at least one of
                                                    // the operands is a string object
    {
        std::cout << word << "\n";
        word[0] = ch;
    }
    std::cout << "After the loop ends, the word is " << word << "\n";
}
