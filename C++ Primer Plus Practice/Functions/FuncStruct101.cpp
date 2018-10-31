//
//  FuncStruct101.cpp
//  C++ Primer Plus Exercises
//
//  Created by Anthony on 03/10/2018.
//

#include <iostream>

struct TravelTime
{
    int hours;
    int mins;
};

constexpr int MinsPerHour {60};

//  Function prototypes
TravelTime sumTime(TravelTime t1, TravelTime t2);
void showTime(TravelTime t);

void showFuncStruct101()
{
    TravelTime day1 {5, 45};
    TravelTime day2 {4, 55};
    
    TravelTime trip {sumTime(day1, day2)};
    std::cout << "Two-day total: ";
    showTime(trip);
    
    TravelTime day3 {4, 32};
    std::cout << "Three-day total: ";
    showTime(sumTime(trip, day3));
}

TravelTime sumTime(TravelTime t1, TravelTime t2)
{
    TravelTime result;
    
    result.mins = (t1.mins + t2.mins) % MinsPerHour;
    result.hours = (t1.hours + t2.hours) +
                   (t1.mins + t2.mins) / MinsPerHour;
    
    return result;
}

void showTime(TravelTime t)
{
    std::cout << t.hours << " hours, " << t.mins << " minutes\n";
}
