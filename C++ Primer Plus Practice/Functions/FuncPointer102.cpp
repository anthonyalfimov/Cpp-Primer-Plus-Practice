//
//  FuncPointer102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 08/10/2018.
//

#include <iostream>

//  Function protorypes
//  Various notations, same signatures

const double* f1(const double ar[], int n);
const double* f2(const double [],   int);
const double* f3(const double *,    int);

void showFuncPointer102()
{
//  Using `typedef` to simplify the declarations
    typedef const double* (*p_func)(const double *, int);
    
    
    double av[3] {1111.2, 2222.2, 3333.6};
    
//  Pointer to a function
    const double* (*p1)(const double *, int) {f1};  // manual type declaration
    auto p2 {f2};                                   // automatic type deduction
//  p_func p3 {f3};                                 // typedef
    
//  Two ways of using a function pointer to call the function
    std::cout << "Using pointers to functions:\n";
    std::cout << "Address         Value\n";
    std::cout
        << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << "\n"
        << p2(av, 3) << ": " << *p2(av, 3) << "\n";
    
    
//  Array of pointers to functions (pa, pb)
//  (auto doesn't work with multiple expression lists)
    const double* (*pa[3])(const double *, int) {f1, f2, f3};
    
//  auto does work for initializing to a single value
    auto pb {pa};
//  equivalent to:
//  const double* (**pb)(const double *, int) {pa};
    
//  typedef:
//  p_func pa2[3] {f1, f2, f3};
    
    
//  Using dereferenced function pointer to call the function
    std::cout << "\nUsing an array of pointers to functions:\n";
    std::cout << "Address         Value\n";
    for (int i = 0; i < 3; i++)
        std::cout << (*pa[i])(av,3) << ": " << *(*pa[i])(av,3) << "\n";
   
//  Using function pointer name to call the function
    std::cout << "\nUsing a pointer to a pointer to a function:\n";
    std::cout << "Address         Value\n";
    for (int i = 0; i < 3; i++)
        std::cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << "\n";
    
    
//  Pointer to an array of function pointers
    std::cout << "\nUsing pointers to an array of function pointers:\n";
    std::cout << "Address         Value\n";
    
//  Manual declaration
    const double* (*(*pc)[3])(const double *, int) {&pa};
    
    std::cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << "\n";
    
//  Automatic type deduction
    auto pd {&pa};
    
    std::cout << (*(*pd)[1])(av, 3) << ": " << *(*(*pd)[1])(av, 3) << "\n";
    
//  typedef:
    p_func (*pe)[3] {&pa};
    
//  Store return value in pe_value:
    const double* pe_value {(*pe)[2](av, 3)};
    std::cout << pe_value << ": " << *pe_value << "\n";
}

//  Simple example funcrions

const double* f1(const double* ar, int n)
{
    return ar;
}

const double* f2(const double ar[], int n)
{
    return ar + 1;
}

const double* f3(const double ar[], int n)
{
    return ar + 2;
}
