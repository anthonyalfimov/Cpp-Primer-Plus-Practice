//
//  Switch102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 22/09/2018.
//

#include <iostream>

// cin does not know how to handle enum type,
// so the input should use integers

// anonymous enum to create named constants
// we could name it, but the name wouldn't be used in this program
enum {red, orange, yellow, green, blue, violet, indigo};

// NB! enum class members are not implicitly converterd to 'int'
// therefore its not the best choice for this application

void showSwitch102()
{
    std::cout << "Enter color code (0-6): ";
    int code;
    std::cin >> code;
    while (code >= red && code <= indigo)
    {
        switch(code)
        {
            case red    : std::cout << "Her lips were red.\n"; break;
            case orange : std::cout << "Her hair was orange.\n"; break;
            case yellow : std::cout << "Her shoes were yellow.\n"; break;
            case green  : std::cout << "Her nails were green.\n"; break;
            case blue   : std::cout << "Her coat was blue.\n"; break;
            case violet : std::cout << "Her eyes were violet.\n"; break;
            case indigo : std::cout << "Her mood was indigo.\n";
        }
        std::cout << "Enter color code (0-6): ";
        std::cin >> code;
    }
    std::cout << "Bye!\n";
}
