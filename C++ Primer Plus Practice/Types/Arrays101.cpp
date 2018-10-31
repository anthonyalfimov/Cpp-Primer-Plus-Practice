//
//  Arrays101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 10/09/2018.
//

#include <iostream>

constexpr int Cities {5};
constexpr int Years  {4};

void showArrays101()
{
    const char * cities[Cities]     // array of pointers to char
    {                               // initialized to addresses of 5 string literals
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "San Gribble",
        "Gribble Vista"
    };                              // an array of char arrays could have been used,
                                    // but it would be redundant and limiting on the character number
                                    // however, it would allow to modify the strings
                                    // a better choice for that is an array of std::string objects
    
                                    // for all cases, same initialization and displaying code would be used
    
    int maxtemps[Years] [Cities]    // 2D array
    {
        {23, 25, 34, 35, 21},       // values for maxtemps[0]
        {21, 28, 33, 32, 24},       // values for maxtemps[1]
        {24, 24, 37, 31, 20},       // values for maxtemps[2]
        {22, 22, 39, 28, 17},       // values for maxtemps[3]
    };
    
    std::cout << "Maximum temperatures for 2014 - 2018\n\n";
    for (int city = 0; city < Cities; ++city)
    {
        std::cout << cities[city] << ":\t";
        for (int year = 0; year < Years; ++year)
            std::cout << maxtemps[year] [city] << "\t";
        std::cout << "\n";
    }
}
