//
//  ControlFlow101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 22/09/2018.
//

#include <iostream>

constexpr int Size {80};

void showControlFlow101()
{
    char line[Size] {};
    int spaces {};
    
    std::cout << "Enter a line of text:\n";
    std::cin.getline(line, Size);
    std::cout << "Complete line:\n" << line << "\n";
    std::cout << "Line through the first period:\n";
    for (int i = 0; line[i] != '\0'; i++)
    {
        std::cout << line[i];       // display character
        if (line[i] == '.')         // break the loop if it's period
            break;
        if (line[i] != ' ')         // skip to the next iteration if space
            continue;
        spaces++;                   // redundant for this example; could have been inside if
    }
    std::cout << "\n" << spaces << " spaces\n" << "Done.\n";
}
