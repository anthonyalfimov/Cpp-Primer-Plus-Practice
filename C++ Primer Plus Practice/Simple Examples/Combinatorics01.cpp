//
//  Combinatorics01.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 28/09/2018.
//
// Probability of winning a "x out of N" Lotto

#include <iostream>

long double lottoProbability(unsigned numbers, unsigned picks);

void showCombinatorics01()
{
    double total, choices;
    std::cout << "Enter the total number of choices on the game card and\n"
                 "the number of picks allowed:\n";
    while ((std::cin >> total >> choices) && choices <= total)
    {
        std::cout << "You have one chance in "
                  << lottoProbability(total, choices)
                  << " of winning.\n" "Next two numbers (q to quit): ";
    }
    std::cout << "Bye!\n";
}

// calculate probability of picking 'picks' numbers out of 'numbers' choices

long double lottoProbability(unsigned numbers, unsigned picks)
{
    long double result {1.0L};
    long double n;
    unsigned p;
    
    for (n = numbers, p = picks; p > 0; n--, p--)
        result *= n / p;
    
    return result;
}
