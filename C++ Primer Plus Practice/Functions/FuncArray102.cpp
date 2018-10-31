//
//  FuncArray102.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 01/10/2018.
//

#include <iostream>

constexpr int MaxEntries {5};

// Function prototypes

/**
 Read property entries into the array and return the number of entires read.
 Input terminates on bad input or negative valuse,
 or when the maximum number of entries has been read

 @param array array to be filled
 @param entriesLimit maximum number of entries allowed
 @return number of entries read
 */
int fillEntires(double array[], int entriesLimit);
/**
 Display property entries from the array

 @param array array to be displayed
 @param entries number of entries
 */
void showEntries(const double array[], int entries);
/**
 Modify all property entries in the array by the same rate.

 @param factor factor to multiply the entries by
 @param array array to be modified
 @param entries number of entries
 */
void revalueEntries(double factor, double array[], int entries);

void showFuncArray102()
{
    double properties[MaxEntries];
    
    int entries {fillEntires(properties, MaxEntries)};
    showEntries(properties, entries);
    
    if (entries > 0)
    {
        std::cout << "Enter revaluation factor: ";
        double factor;
        while (!(std::cin >> factor) || factor < 0)   // bad input
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input! Please enter a number: ";
        }
        
        revalueEntries(factor, properties, entries);
        showEntries(properties, entries);
    }
    std::cout << "Done!\n";
}

int fillEntires(double ar[], int limit)
{
    double value;
    int i;      // array iterator
    
    for (i = 0; i < limit; ++i)
    {
        std::cout << "Enter value #" << i + 1 << ": ";
        std::cin >> value;
        if (!std::cin)
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            std::cout << "Bad input! Input process terminated.\n";
            break;
        }
        else if (value < 0)
        {
            std::cout << "Negative input! Input process terminated.\n";
            break;
        }
        ar[i] = value;
    }
    
    return i;
}

void showEntries(const double ar[], int max)
{
    for (int i = 0; i < max; ++i)
        std::cout << "Property #" << i + 1 << ": $" << ar[i] << "\n";
}

void revalueEntries(double factor, double ar[], int max)
{
    for (int i = 0; i < max; ++i)
        ar[i] *= factor;
}
