//
//  CharacterFunctions101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 18/09/2018.
//

#include <iostream>
#include <cctype>       // prototypes for character functions

void showCharacterFunctions101()
{
    std::cout << "Enter text for analysis, and type # "
                 "to terminate input.\n";
    
    char ch;
    int whitespace {};
    int digits {};
    int chars {};
    int punct {};
    int others {};
    
    std::cin.get(ch);
    
    while (ch != '#')           // test for sentinel character
    {
        if (std::isalpha(ch))        // is alphabetic character?
            chars++;
        else if (std::isspace(ch))   // is whitespace?
            whitespace++;
        else if (std::isdigit(ch))   // is digit?
            digits++;
        else if (std::ispunct(ch))   // is puntuation?
            punct++;
        else
            others++;
        
        std::cin.get(ch);
    }
    std::cout << chars << " letters,\n"
              << whitespace << " whitespaces,\n"
              << digits << " digits,\n"
              << punct << " punctuations,\n"
              << others << " others.\n";
}
