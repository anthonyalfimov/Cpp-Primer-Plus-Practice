//
//  Struct101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 20/07/2018.
//

#include <iostream>

void showStruct101()
{
    struct Inflatable           // local and external declaration are possible
    {                           // for the structure
        char name[20];
        float volume;
        double price;
    };
    
    Inflatable guest
    {
        "Glorious Gloria",      // name value
        1.88,                   // volume value
        29.99                   // price value
    };                          // initializer list is spread over five lines for visibility
    
    Inflatable pal {"Audacious Arthur", 3.12, 32.99};
    
    std::cout << "Expand your guest list with " << guest.name
    << " and " << pal.name << "!\n"
    << "You can have both for $" << guest.price + pal.price << "!\n";
}
