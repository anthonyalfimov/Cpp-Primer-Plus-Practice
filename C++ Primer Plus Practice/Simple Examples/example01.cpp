//
//  example01.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 18/09/2018.
//

#include <iostream>

constexpr int Size {6};

void showExample01()
{
    float naaq[Size] {};
    std::cout << "Enter the NAAQs (New Age Awareness Quotients) "
                 "of\nyour neighbors. Program terminates "
                 "when you make\n" << Size << " entries "
                 "or enter a negative value.\n";
    int i {};
    float temp;
    std::cout << "First value: ";
    std::cin >> temp;
    while (i < Size && temp >= 0)   // two exit conditions: filled array and negative entry
    {
        naaq[i] = temp;
        ++i;
        if (i < Size)               // if there's room left in the array ...
        {
            std::cout << "Next value: ";
            std::cin >> temp;       // ... get next value
        }
    }
    if (0 == i)
        std::cout << "No data!\n";
    else
    {
        std::cout << "Enter your NAAQ: ";
        float you;
        std::cin >> you;
        int count {};
        for (int j = 0; j < i; ++j)
            if (naaq[j] > you)
                ++count;
        std::cout << count << " of your neighbors have greater awareness of\n"
                              "the New Age than you do.\n";
    }
}
