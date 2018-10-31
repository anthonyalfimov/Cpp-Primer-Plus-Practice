//
//  TempExplicitSpec101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 22/10/2018.
//

#include <iostream>

namespace TempExplicitSpec101
{
    constexpr int Size {40};
    
    struct Job
    {
        char name[Size];
        double salary;
        int floor;
    };
    
//    Template
    template <typename T>
    void swap(T &a, T &b);
    
//    Explicit specialization
    template <>
    void swap<Job>(Job &j1, Job &j2);       // <Job> is optional in this case
    
    void show(Job&);
}

using namespace TempExplicitSpec101;

void showTempExplicitSpec101()
{
    std::cout.precision(2);
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    //    fixed - flad: fixed decimal notation
    //    floatfield - mask: scientific OR fixed
    //
    //    mask defines which flags can be altered,
    //    flags defines which flags of those to be altered should be set
    
    int i {10}, j {20};
    std::cout << "i, j = " << i << ", " << j << ".\n";
    std::cout << "Using compiler-generated int swapper:\n";
    swap(i, j);     // type deduced from arguments: int
    std::cout << "Now i, j = " << i << ", " << j << ".\n";
    
    Job sue {"Susan Yaffee", 73000.60, 7};
    Job sidney {"Sidney Taffee", 78060.72, 9};
    
    std::cout << "Before job swapping:\n";
    show(sue);
    show(sidney);
    
    swap(sue, sidney);      // uses explicit specification
    
    std::cout << "After job swapping:\n";
    show(sue);
    show(sidney);
}

template <typename T>
void TempExplicitSpec101::swap(T &a, T &b)
{
    T tmp {a};
    a = b;
    b = tmp;
}

//  Swaps only the salary and the floor, leaving name intact
template <>
void TempExplicitSpec101::swap<Job>(Job &j1, Job &j2)
{
    double salaryTmp;
    int floorTmp;
    
    salaryTmp = j1.salary;
    j1.salary = j2.salary;
    j2.salary = salaryTmp;
    
    floorTmp = j1.floor;
    j1.floor = j2.floor;
    j2.floor = floorTmp;
}

void TempExplicitSpec101::show(Job& j)
{
    std::cout << j.name << ": $" << j.salary
              << " on floor " << j.floor << "\n";
}
