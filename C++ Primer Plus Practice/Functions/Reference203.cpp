//
//  Reference203.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 28/11/2018.
//
//  This file demonstrates the possibility of using reference variables
//      for dynamic memory allocation. This approach is a fun exercise that,
//      however, does not have any benefits.
//

#include <iostream>

namespace Reference203
{
    struct Verbose
    {
        int data;
        Verbose(int value = 0)
        {
            data = value;
            std::cout << "Constructor called\n";
        }
        ~Verbose()
        {
            std::cout << "Destructor called\n";
        }
    };
}

void showReference203()
{
    using namespace Reference203;
    
    // Create a reference variable and assign dynamically allocated memory to it
    //     by dereferencing the pointer returned by `new`;
    //     initialize dynamically allocated struct as well.
    Verbose& foo = *(new Verbose {5});
    std::cout << foo.data << "\n";
    
    // NB! Reference variable does not manage the memory of a variable it refers to.
    //
    //     When created, it does no allocate any memory, but only assigns a new alias to
    //     an existing memory location.
    //     - If that memory location gets deallocated, reference variable still refers to
    //     it.
    //     - If the reference variable goes out of scope, it does not deallocate the
    //     memory it refers to.
    
    // Deallocate the struct:
    delete &foo;
}
