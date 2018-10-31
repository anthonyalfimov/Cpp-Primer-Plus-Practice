//
//  FuncArray301.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/10/2018.
//

#include <iostream>
#include <array>
#include <string>

//  Constant data
constexpr int Seasons {4};
const std::array<std::string, Seasons> SeasonNames
{
    "Spring", "Summer", "Autumn", "Winter"
};

//  Function prototypes
void fillExpenses(std::array<double, Seasons> * p_array);
void showExpenses(std::array<double, Seasons> array);

void showFuncArray301()
{
    std::array<double, Seasons> expenses;
    fillExpenses(&expenses);
    showExpenses(expenses);
}

void fillExpenses(std::array<double, Seasons> * p_array)
{
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << "Enter " << SeasonNames[i] << " expenses: ";
        std::cin >> (*p_array)[i];      // address the object, not its memory directly
                                        // or use `p_array->at(i)`
    }
}

void showExpenses(std::array<double, Seasons> array)
{
    double total {};
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < Seasons; i++)
    {
        std::cout << SeasonNames[i] << ": $" << array[i] << "\n";
        total += array[i];
    }
    std::cout << "TOTAL : $" << total;
}
