//
//  Reference202.cpp
//  C++ Primer Plus Exercises
//
//  Passing an array by reference vs passing a pointer to array
//  for use with range-based for loop
//

#include <iostream>

namespace Reference202
{
    constexpr int size {5};
    
    void print_by_pointer  (const int (*)[size]);
    void print_by_reference(const int (&)[size]);
}

void showReference202()
{
    using namespace Reference202;
    
    int array[size] {1, 2, 3, 4, 5};
    
//    Create an array reference variable:
    int (&ref)[size] {array};
    
    std::cout << "Pass a pointer to array:\n";
    print_by_pointer(&ref);
    
    std::cout << "\nPass array by reference:\n";
    print_by_reference(ref);
}

namespace Reference202
{
    void print_by_pointer(const int (*a)[size])
    {
        for (int value : *a)
            std::cout << value << "\t";
        std::cout << "\n";
    }
    
    void print_by_reference(const int (&a)[size])
    {
        for (int value : a)
            std::cout << value << "\t";
        std::cout << "\n";
    }
}


