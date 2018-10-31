//
//  TrailingReturn101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 25/10/2018.
//

#include <iostream>

namespace TrailingReturn101
{
//    Use auto to declare return type
    template<class T1, class T2>
    auto sum(T1 a, T2 b)
    {
        return a + b;
    }
    
//    Use trailing return type and decltype
    template<class T1, class T2>
    auto sumTR(T1 x, T2 y) -> decltype(x + y)
    {
        return x + y;
    }
}

using namespace TrailingReturn101;

void showTrailingReturn101()
{
    long double data {5.123e4L};
    char ch {' '};
    
    std::cout << "Auto:     " << sum(data, ch) << "\n";
    std::cout << "decltype: " << sumTR(data, ch) << "\n";
}
