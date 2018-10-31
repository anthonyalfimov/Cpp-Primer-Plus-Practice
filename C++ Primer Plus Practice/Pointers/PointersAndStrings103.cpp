//
//  PointersAndStrings103.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 08/08/2018.
//

#include <iostream>
#include <cstring>

char * getname()
{
    static int maxSize {80};
    char temp[maxSize];                              // temporary storage
    std::cout << "Enter last name: ";
    std::cin.getline(temp, maxSize);                 // get string
    char * pn = new char[strlen(temp) + 1];     // allocate new smaller storage
    std::strcpy(pn, temp);                      // copy string to new storage
    
    return pn;
}

void printString(const char * string)
{
    std::cout << string << " at " << (int *) string << "\n";
}

void showPointersAndStrings103()
{
    char * name = getname();    // create pointer and assign address
    printString(name);
    delete [] name;             // free memory
                                // NB! poor practice to use 'new' and 'delete' in different scopes
    
    name = getname();   // allocate new string
    printString(name);
    delete [] name;
}
