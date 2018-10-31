//
//  Struct103.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 23/07/2018.
//

#include <iostream>

void showStruct103()
{
    struct Inflatable
    {
        char name[20];
        float volume;
        double price;
    };
    
    Inflatable guests[2]                // array of structs with brace initialization
    {
        {"Bambi",    0.5f,    21.99},
        {"Godzilla", 2000.0f, 565.99}
    };
    
    std::cout << "The guests " << guests[0].name << " and " << guests[1].name
              << "\nhave a combined volume of " << guests[0].volume + guests[1].volume
              << " cubic feet.\n";
}
