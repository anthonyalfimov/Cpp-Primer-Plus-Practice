//
//  FuncPointer101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 05/10/2018.
//

#include <iostream>

//  Function prototypes
double betsy(int);
double pam(int);

void estimate(int lines, double (*pfun)(int));
// OR: void estimate(int lines, double (*)(int));
// OR: void estimate(int lines, double (int));

void showFuncPointer101()
{
    int code;
    std::cout << "How many lines of code do you need? ";
    std::cin >> code;
    std::cout << "Here's Betsy's estimate:\n";
    estimate(code, betsy);
    std::cout << "Here's Pam's estimate:\n";
    estimate(code, pam);
}

double betsy(int lns)
{
    return 0.05 * lns;
}

double pam(int lns)
{
    return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pfun)(int))
// OR: void estimate(int lines, double pfun(int))
{
    std::cout
        << lines << " lines will take "
        << pfun(lines) << " hour(s)\n";
}
