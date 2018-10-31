//
//  PartialOrdering101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 25/10/2018.
//

#include <iostream>

namespace PartialOrdering101
{
//  Template A: array elements are data
    template <typename T>
    void showArray(T arr[], int n);
    
//  Template B: array elements are pointers
    template <typename T>
    void showArray(T* arr[], int n);
    
//  Struct name size
    constexpr int StringSize {50};
    
    struct Debts
    {
        char name[StringSize];
        double amount;
    };
}

using namespace PartialOrdering101;

void showPartialOrdering101()
{
//    Int array:
    int things[6] {13, 31, 103, 301, 310, 130};
//    Struct array:
    struct Debts mr_E[3]        // keyword `struct` is optional in C++ in declaration
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
//    Pointer-to-double array:
    double* pd[3];              // set pointers to the amount members of mr_E struct
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;
    
    std::cout << "Listing Mr. E's amounts of things:\n";
//    things is an array of int - uses Template A
    showArray(things, 6);
    
    std::cout << "Listing Mr. E's debts:\n";
//    pd is an array of pointers-to-double - uses Template B (more specialized)
    showArray(pd, 3);
}

//  Template A
template <typename T>
void PartialOrdering101::showArray(T arr[], int n)
{
    std::cout << "Template A\n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << "\n";
}

//  Template B
template <typename T>
void PartialOrdering101::showArray(T* arr[], int n)
{
    std::cout << "Template B\n";
    for (int i = 0; i < n; i++)
        std::cout << *arr[i] << ' ';
    std::cout << "\n";
}
