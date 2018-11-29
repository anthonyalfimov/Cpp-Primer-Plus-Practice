//
//  Enums101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 26/07/2018.
//

#include "Enums101.hpp"     // needed to demonstrate opaque enum declaration
#include <iostream>

// Defining the forward-declared enum class
enum class Type {A, B, C};

void showEnums101()
{
    // Unscoped enum
    enum spectrum {red, green, blue};
    spectrum band = green;
    std::cout << "Band code: " << band << "\n";
    
    // Unscoped anonymous enum works as a group definition of symbolic integral constants
    // of the underlying type
    
    // Scoped enum
    enum class Color { red, green = 20, blue = 40 };
    Color r = Color::blue;
    switch(r)
    {
        case Color::red  : std::cout << "red\n";   break;
        case Color::green: std::cout << "green\n"; break;
        case Color::blue : std::cout << "blue\n";  break;
    }
    
    // Using forward-declared enum class
    Type license = Type::A;
    if (license == Type::B)
        std::cout << "Success!\n";
    else
        std::cout << "Not OK!!!\n";
    
    // Addressing a class-member unscoped enum with explicit type specification
    struct Fun
    {
        enum Features : int {boobs, ass};
        Features favourite;
        Features second_favourite;
    };
    Fun x;
    Fun* p = &x;
    
    x.favourite = x.ass;
    x.second_favourite = p->boobs;
    
    switch (x.favourite) {
        case Fun::boobs :
            std::cout << "My favourite thing about you is boobs\n";
            break;
            
        // In case of scoped enum, only the following notation works:
        case Fun::Features::ass :
            std::cout << "My favourite thing about you is ass\n";
    }
}



