//
//  TempOverload101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 22/10/2018.
//

#include <iostream>

namespace TempOverload101
{
//    Original template
    template <typename T>   // or class T
    void swap(T &a, T &b);
    
//    New template - overload
    template <typename T>
    void swap(T* a, T* b, int size);   // template function with different signature
    
//    Display function should be a template as well
    template <typename T>
    void show(T a[], int size);
    
    constexpr int Limit {8};
}

using namespace TempOverload101;

void showTempOverload101()
{
    int i {10}, j {20};
    std::cout << "i, j = " << i << ", " << j << ".\n";
    std::cout << "Using compiler-generated int swapper:\n";
    swap(i, j);     // type deduced from arguments: int
    std::cout << "Now i, j = " << i << ", " << j << ".\n";
    
    int d1[Limit] {0, 7, 0, 4, 1, 7, 7, 6};
    int d2[Limit] {0, 7, 2, 0, 1, 9, 6, 9};
    std::cout << "Original arrays:\n";
    show(d1, Limit);
    show(d2, Limit);
    swap(d1, d2, Limit);    // matches the new template
    std::cout << "Swapped arrays:\n";
    show(d1, Limit);
    show(d2, Limit);
}

// Function template definition
template <typename T>
void TempOverload101::swap(T &a, T &b)
{
    T tmp {a};      // temporary variable of type T
    a = b;
    b = tmp;
}

template <typename T>
void TempOverload101::swap(T* a, T* b, int n)
{
    T tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;
    }
}

template <typename T>
void TempOverload101::show(T a[], int max)
{
    std::cout
        << a[0] << a[1] << "/"
        << a[2] << a[3] << "/";
    for (int i = 4; i < max; i++)
        std::cout << a[i];
    std::cout << "\n";
}
