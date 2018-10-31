//
//  FuncTemp101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 22/10/2018.
//

#include <iostream>

namespace FuncTemp101
{
//    Function template prototype
    template <typename T>   // or class T
    void swap(T &a, T &b);
}

using namespace FuncTemp101;

void showFuncTemp101()
{
    int i {10};
    int j {20};
    std::cout << "i, j = " << i << ", " << j << ".\n";
    std::cout << "Using compiler-generated int swapper:\n";
    swap(i, j);     // type deduced from arguments: int
    std::cout << "Now i, j = " << i << ", " << j << ".\n";
    
    double x {24.5};
    double y {81.7};
    std::cout << "x, y = " << x << ", " << y << ".\n";
    std::cout << "Using compiler-generated double swapper:\n";
    swap(x, y);     // type deduced from arguments: double
    std::cout << "Now x, y = " << x << ", " << y << ".\n";
}

// Function template definition
template <typename T>
void FuncTemp101::swap(T &a, T &b)
{
    T tmp {a};      // temporary variable of type T
    a = b;
    b = tmp;
}
