//
//  ForcedResolution101.cpp
//  C++ Primer Plus Exercises
//
//  This program shows how to influence the overload resolution
//

#include <iostream>

namespace ForcedResolution101
{
//  Overload #1 - return the lesser of two values
    template<class T>
    T lesser(T a, T b) { return a < b ? a : b; }
    
//  Overload #2 - return the smaller of absolute values of two ints
    int lesser(int a, int b)
    {
        a = a < 0 ? -a : a;     // work with the absolute value
        b = b < 0 ? -b : b;
        return a < b ? a : b;
    }
}

using namespace ForcedResolution101;

void showForcedResolution101()
{
    int    m {20},   n {-30};
    double x {15.5}, y {25.9};
    
    std::cout << lesser(m, n) << "\n";          // use #2
    std::cout << lesser(x, y) << "\n";          // use #1 with T = double
    std::cout << lesser<>(m, n) << "\n";        // force using template (#1 with int)
    std::cout << lesser<int>(x, y) << "\n";     // use the explicit instantiation
                                                // int version of the template #1
}
