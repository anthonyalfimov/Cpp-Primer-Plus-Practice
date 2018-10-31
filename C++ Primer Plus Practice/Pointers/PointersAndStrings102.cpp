//
//  PointersAndStrings102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 06/08/2018.
//

#include <iostream>
#include <cstring>

void showPointersAndStrings102()
{
    char animal[20] {"bear"};       // animal holds bear
    const char * bird {"wren"};     // bird holds address of string
    char * ps;                      // uninitialized!
    
    std::cout << animal << " and "  // display bear
              << bird << "\n";      // display wren
    
    std::cout << "Enter a kind of animal: ";    // ok if input < 20 characters
    std::cin >> animal;
    
    // Copy the address of the string
    ps = animal;                    // set ps to the address of the first char in
                                    // animal
    std::cout << ps << "!\n";
    std::cout << "Before using strcpy():\n"
    << animal << " at " << (int *) animal << "\n"   // cast (to any other pointer) to display
    << ps << " at " << (int *) ps << "\n";          // address rather than the string
    
    // Copy the string itself
    ps = new char[std::strlen(animal) + 1];     // get new storage
                                                // NB! strlen() returns string length
                                                // not accounting for '\0'
    std::strcpy(ps, animal);
    
    std::cout << "After using strcpy():\n"
    << animal << " at " << (int *) animal << "\n"
    << ps << " at " << (int *) ps << "\n";
    
    // Demonstrate that the result is two separate strings
    ps[0] = 'Z';
    std::cout << animal << "-" << ps << "\n";
    
    delete [] ps;
}
