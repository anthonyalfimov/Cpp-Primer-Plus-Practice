//
//  AutoVSdecltype101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 25/10/2018.
//

#include <iostream>
#include <array>
#include <typeinfo>         // for typeid

namespace AutoVSdecltype101
{
    template<typename T1, typename T2>
    void f(T1& x, T2& y)
    {
        auto sum = x + y;                   // auto and decltype can be used equivalently here
        std::cout << "Sum: " << sum << ": " << typeid(sum).name() << "\n\n";
        
        typedef decltype(x + y) xyType;     // can't use auto if not a declaration
                                            // use typedef to make casts easier to read
        std::array<xyType, 3> array {xyType(x), xyType(y), x + y};
        
        for (int i = 0; i < 3; i++)
            std::cout << array[i] << ": " << typeid(array[i]).name() << "\n";
        
        auto a = x;             // x is a reference, a is not
        a = 0;                  // the original value will not be changed
        
        decltype(y) b = y;      // y is a reference, so is b
        b = 0;                  // the original value will be changed
    }
}

using namespace AutoVSdecltype101;

void showAutoVSdecltype101()
{
    char a1 = 'A';
    double a2 = 15.54;
    
    std::cout
        << "Referenced values before the function call:\n"
        << "a = " << a1 << ", b = " << a2
        << "\n\nFunction call:\n";
    f(a1, a2);
    std::cout
        << "\nReferenced values after the function call:\n"
        << "a = " << a1 << ", b = " << a2 << "\n";
}
