//
//  Recursion102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 04/10/2018.
//
//  Recursion with Multiple Recursive calls
//

#include <iostream>

constexpr int Length {66};
constexpr int Divs   {6};

void subdivideString(char* str, int low, int high, int level);

void showRecursion102()
{
    char ruler[Length];
    for (int i = 1; i < Length - 2; i++)    // fill the middle with spaces
        ruler[i] = ' ';
    ruler[Length - 1] = '\0';               // null termination
    int max = Length - 2;                   // max ruler index
    int min = 0;                            // min ruler index
    ruler[min] = ruler[max] = '|';          // ruler borders
    
    std::cout << ruler << "\n";             // print first subdivision level
    
    for (int i = 1; i <= Divs; i++)
    {
        subdivideString(ruler, min, max, i);
        std::cout << ruler << "\n";
        
        for (int j = 1; j < Length - 2; j++)    // reset to a blank ruler
            ruler[j] = ' ';                     // not necessary - only to demonstrate
    }                                           // subdivision from scratch using recursion
}

void subdivideString(char* str, int low, int high, int level)
{
    if (level == 0) return;     // recursion exit condition -  no subdivision required
    
    int mid = (high + low) / 2;
    str[mid] = '|';
    subdivideString(str, low, mid, level - 1);
    subdivideString(str, mid, high, level - 1);
}
