//
//  VectorAndArray101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 15/08/2018.
//

#include <iostream>
#include <vector>
#include <array>

void showStdVectorAndArray101()
{
// built-in array
    double a1[4] {1.2, 2.4, 3.6, 4.8};
    
// vector template object
    // we can either use the initializer list to init a vector:
    std::vector<double> v1 {1.0/3.0, 1.0/5.0, 1.0/7.0, 1.0/9.0};
    
    // or use the constructor to init the vector of required size:
    std::vector<double> v2(4);          // elements initialized to 0
    std::vector<double> v3(4, 9.9);     // elements initialized to 9.9
    
// array template object
    std::array<double, 4> a2 {3.14, 2.72, 1.62, 1.41};
    std::array<double, 4> a3;
    
    a3 = a2;        // valid for arrays of the same type and size
    
    std::cout << "Vectors:\n"
              << "v1[2]: " << v1[2] << " at " << &v1[2] << "\n"
              << "v2[2]: " << v2[2] << " at " << &v2[2] << "\n"
              << "v3[2]: " << v3[2] << " at " << &v3[2] << "\n"
              <<"Arrays:\n"
              << "a1[2]: " << a1[2] << " at " << &a1[2] << "\n"
              << "a2[2]: " << a2[2] << " at " << &a2[2] << "\n"
              << "a3[2]: " << a3[2] << " at " << &a3[2] << "\n";
}
