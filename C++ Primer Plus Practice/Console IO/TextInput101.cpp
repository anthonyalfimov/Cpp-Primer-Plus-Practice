//
//  TextInput101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 22/08/2018.
//

#include <iostream>

void showTextInput101()
{
    char ch;
    int count {};           // use basic input
    std::cout << "Enter characters; enter # to quit:\n";
    std::cin.get(ch);       // get a character, use cin.get(char) function
                            // to read all characters incl. whitespaces
    while (ch != '#')       // test the character against the 'sentinel' character
    {
        std::cout << ch;    // echo the character
        ++count;            // count the character
        std::cin.get(ch);   // get the next character
    }
    std::cout << "\n" << count << " characters read.\n";
}
