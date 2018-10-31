//
//  DynamicStructs101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 08/08/2018.
//

#include <iostream>

void showDynamicStructs101()
{
    struct Inflatable       // structure definitiion
    {
        char name[20];
        float volume;
        double price;
    };
    
    Inflatable *  ps {new Inflatable};  // memory allocation for structure
    std::cout << "Enter name of inflatable item: ";
    std::cin.get(ps->name, 20);         // read line into the char array
                                        // name can be an array name or a char pointer
    std::cout << "Enter volume in cubic feet: ";
    std::cin >> (*ps).volume;           // use dereferencing for member access
    std::cout << "Enter price: ";
    std::cin >> ps->price;
    
    std::cout << "Name: " << (*ps).name << "\n"
              << "Volume: " << ps->volume << " cubic feet\n"
              << "Price: $" << ps->price << "\n";
    
    delete ps;
}

