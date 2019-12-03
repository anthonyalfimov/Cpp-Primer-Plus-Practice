//
//  Exceptions301.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 03/12/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include <new>          // for bad_alloc
#include <cstdlib>      // for exit(), EXIT_FAILURE

namespace
{
    struct BigData
    {
        double buffer[200000];              // 1,600,000 bytes
    };
}

void showExceptions301()
{
    BigData* ptr;
    
    try
    {
        std::cout << "Trying to get a big block of memory:\n";
        ptr = new BigData[100000000];       // 100,600,000,000,000 bytes
        std::cout << "Execution continues past the memory allocation request\n";
    }
    catch (std::bad_alloc& badAllocException)
    {
        std::cout << "> exception caught:\n";
        std::cout << badAllocException.what() << "\n";
        std::exit(EXIT_FAILURE);
    }
    
    std::cout << "Memory successfully allocated!\n";
    ptr[0].buffer[0] = 4.0;
    std::cout << ptr[0].buffer[0] << "\n";
    
    delete [] ptr;
}
