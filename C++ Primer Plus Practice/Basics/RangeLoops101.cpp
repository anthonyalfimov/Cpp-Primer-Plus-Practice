//
//  RangeLoops101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 21/08/2018.
//

#include <iostream>
#include <string>

// The only way to pass an array to a function so that
// it is usable in a Range-based for loop that i found
// is to pass the pointer-to-array
void printPrices(double (*array) [5])
{
    for (double x : *array)
        std::cout << "$" << x << "\n";
}

void showRangeLoops101()
{
    double prices[5] {4.99, 10.99, 6.99, 7.99, 8.49};
    double total {};
    
    // Sum all items in array
    for (double x : prices)
        total += x;
    
    // Display all items in array
    printPrices(&prices);
    std::cout << "Total: $" << total << "\n";
    
    // Use with STL containers
    std::string note {"SALE"};
    for (char c : note)
        std::cout << c << "\n";
    
    // Pass by reference to modify within the loop
    for (double &x : prices)
        x *= 0.80;
    
    printPrices(&prices);
}
