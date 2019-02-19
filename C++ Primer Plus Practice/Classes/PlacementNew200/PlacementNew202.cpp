//
//  PlacementNew202.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 19/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  This program fixes the issues with using Placement New introduced in PlacementNew201
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

void showPlacementNew202()
{
    char* buffer = new char[BUF];           // get a block of memory on the heap
    
    JustTesting *pc1, *pc2;
    
    pc1 = new (buffer) JustTesting;         // create object in buffer
    pc2 = new JustTesting("Heap1", 20);     // create object on heap
    
    std::cout << "\nMemory block addresses:\n"
    << "buffer: " << (void*) buffer << " -- " << pc1 << "\n"    // buffer as pointer, not C-string
    << "heap:   " << pc2 << "\n";
    
    std::cout << "\nMemory contents:\n";
    std::cout << pc1 << ": ";
    pc1->show();
    std::cout << pc2 << ": ";
    pc2->show();
    
    std::cout << "\n";
    JustTesting *pc3, *pc4;
    pc3 = new (buffer + sizeof(JustTesting)) JustTesting("Better Idea", 6);
    pc4 = new JustTesting("Heap2", 10);
    
    std::cout << "\nMemory contents:\n";
    std::cout << pc3 << ": ";
    pc3->show();
    std::cout << pc4 << ": ";
    pc4->show();
    
    std::cout << "\n";
    delete pc2;         // free Heap1
    delete pc4;         // free Heap2
    
//  Explicitely destroy Placement New Objects
//  NB! Objects should be destroyed in order opposite to their construction!
//      -> Later objects might have dependencies on earlier ones.
    pc3->~JustTesting();
    pc1->~JustTesting();
    
//  The buffer is freed after all objects in it are destroyed
    delete [] buffer;   // free buffer,
    
    std::cout << "\nDone.\n";
}
