//
//  ParameterTemplates101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 14/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Example of using templates as template parameters
//

#include <iostream>
#include "StackType02.hpp"

namespace
{
    template <template <typename Type> class Thing>
    class Crab
    {
    public:
        Crab() {}
        
        // Assumes that class Thing has push() and pop() methods
        bool push (int a, double x) { return m1.push (a) && m2.push (x); }
        bool pop (int& a, double& x) { return m1.pop (a) && m2.pop (x); }
        
    private:
        Thing<int> m1;          // use the parameter template class to create members
        Thing<double> m2;
    };
}

void showParameterTemplates101()
{
    using ClassTemplates101::Stack;
    
    Crab<Stack> nebula;         // Stack must match `template <typename Type> class Thing`
    
    int dataA;
    double dataX;
    
    std::cout << "Enter int-double pairs, such as \"4 3.5\", \"0 0\" to end:\n";
    
    while (std::cin >> dataA >> dataX && dataA > 0 && dataX > 0.0)
    {
        if (! nebula.push (dataA, dataX))
            break;
    }
    
    while (nebula.pop (dataA, dataX))
        std::cout << dataA << ", " << dataX << "\n";
    
    std::cout << "\nDone.\n";
}
