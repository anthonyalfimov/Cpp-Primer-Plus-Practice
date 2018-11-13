//
//  PlacementNew101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 13/11/2018.
//

#include <iostream>
#include <new>                  // for placement new

constexpr int BUF {512};        // memory chunk size - 512 bytes
constexpr int size {5};

static char buffer[BUF];        // memory chunk to use for placement new allocations
                                // static allocation, internal linkage

void showPlacementNew101()
{
    double *pd1, *pd2;
    int i;                      // iterator
    
    std::cout << "Calling new and placement new:\n";
    
    pd1 = new double[size];                 // use heap
    pd2 = new (buffer) double [size];       // use buffer array
    
//  Fill both arrays:
    for (i = 0; i < size; i++)
        pd2[i] = pd1[i] = 1000 + 20.0 * i;
    
//  pd1 is heap-allocated, pd2 is allocated in a static-allocated buffer
    std::cout << "Memory addresses:\n"
              << " heap: " << pd1 << "  static: " << (void*) buffer << "\n";
                                            //  cast to void* to avoid printing as a string
    
    std::cout << "Memory contents:\n";
    for (i = 0; i < size; i++)
    {
        std::cout
            << pd1[i] << " at " << &pd1[i] << "; "
            << pd2[i] << " at " << &pd2[i] << "\n";
    }
    
    std::cout << "Calling new and placement new a second time:\n";
    
    double *pd3, *pd4;
    pd3 = new double[size];                 // find new address
    pd4 = new (buffer) double[size];        // overwrite old data
    
//  Fill both arrays:
    for (i = 0; i < size; i++)
        pd4[i] = pd3[i] = 1000 + 40.0 * i;
    
    std::cout << "Memory contents:\n";
    for (i = 0; i < size; i++)
    {
        std::cout
        << pd3[i] << " at " << &pd3[i] << "; "
        << pd4[i] << " at " << &pd4[i] << "\n";
    }
    
    std::cout << "Calling new and placement new a third time:\n";
    
    delete [] pd1;                          // free the memory used by pd1 array
    pd1 = new double[size];                 // find new address
    pd2 = new (buffer + size * sizeof(double)) double[size];
                                            // allocate in a new place within the buffer
    
//  Fill both arrays:
    for (i = 0; i < size; i++)
        pd2[i] = pd1[i] = 1000 + 60.0 * i;
    
    std::cout << "Memory contents:\n";
    for (i = 0; i < size; i++)
    {
        std::cout
        << pd1[i] << " at " << &pd1[i] << "; "
        << pd2[i] << " at " << &pd2[i] << "\n";
    }
    
    delete [] pd1;
    delete [] pd3;
    
//  `delete` can only be used with dynamically allocated memory;
//      however, the buffer used for placement new is allocated in static memory
//      and, therefore, its memory addresses can't be used with `delete`
//  Arrays allocated with placement new will be deallocated when
//      the statically allocated buffer gets deallocated on program termination
}
