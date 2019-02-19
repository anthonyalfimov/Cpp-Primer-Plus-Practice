//
//  PlacementNew201.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 19/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Example of potential issues when using Placement New with classes
//

#include <iostream>
#include <string>
#include <new>              // for placement new

constexpr int BUF = 512;    // buffer size

namespace
{
    class JustTesting
    {
    private:
        std::string words;
        int number;
    public:
        JustTesting(const std::string& s = "Just Testing", int n = 0)
        {
            words = s;
            number = n;
            std::cout << words << " constructed\n";
        }
        ~JustTesting()
        {
            std::cout << words << " destroyed\n";
        }
        void show() const
        {
            std::cout << words << ", " << number << "\n";
        }
        
    };
}

void showPlacementNew201()
{
    char* buffer = new char[BUF];           // get a block of memory on the heap
    
    JustTesting *pc1, *pc2;
    
    pc1 = new (buffer) JustTesting;         // create object in buffer
    pc2 = new JustTesting("Heap1", 20);     // create object on heap
    
    std::cout << "\nMemory block addresses:\n"
              << "buffer: " << (void*) buffer << " -- " << pc1 << "\n"
              << "heap:   " << pc2 << "\n";
    
    std::cout << "\nMemory contents:\n";
    std::cout << pc1 << ": ";
    pc1->show();
    std::cout << pc2 << ": ";
    pc2->show();
    
    std::cout << "\n";
    JustTesting *pc3, *pc4;
    pc3 = new (buffer) JustTesting("Bad Idea", 66);     // overwrite existing object
                                                        //     without deleting it!
    pc4 = new JustTesting("Heap2", 10);
    
    std::cout << "\nMemory contents:\n";
    std::cout << pc3 << ": ";
    pc3->show();
    std::cout << pc4 << ": ";
    pc4->show();
    
    std::cout << "\n";
    delete pc2;         // free Heap1
    delete pc4;         // free Heap2
    
    delete [] buffer;   // free buffer,
                        //     no destructor(s) called as objects were not explicitely deleted
    
    std::cout << "\nDone.\n";
}
