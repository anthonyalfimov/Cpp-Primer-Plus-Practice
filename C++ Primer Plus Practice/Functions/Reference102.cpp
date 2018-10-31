//
//  Reference102.cpp
//  C++ Primer Plus Exercises
//
//  Returning a reference
//

#include <iostream>
#include <string>

namespace Reference102
{
    struct FreeThrows
    {
        std::string name;
        int made;
        int attempts;
        float percent;
    };
    
    void display(const FreeThrows&);
    void setPercent(FreeThrows&);
    /**
     Add attempts and throws from source to target, recalculate target percent
     and return a reference to the target.

     @return reference to target
     */
    FreeThrows& accumulate(FreeThrows& target, const FreeThrows& source);
}

using namespace Reference102;

void showReference102()
{
//    Partial initializations: remaining members set to 0
    FreeThrows one {"Ifelsa Branch", 13, 14};
    FreeThrows two {"Andor Knott", 10, 16};
    FreeThrows three {"Minnie Max", 7, 9};
    FreeThrows four {"Whily Looper", 5, 9};
    FreeThrows five {"Long Lang", 6, 14};
    FreeThrows team {"Throwgoods"};
    
//    No initialization
    FreeThrows dup;
    
    setPercent(one);
    display(one);
    accumulate(team, one);
    display(team);
    
//    Use return value as argument
    display(accumulate(team, two));
    accumulate(accumulate(team, three), four);
    display(team);
    
//    Use return value in assignment
    dup = accumulate(team, five);   // copy modified team struct to dup struct
    std::cout << "Displaying dup after assignment:\n";
    display(dup);
    
    setPercent(four);
//    Ill-advised assignment
    accumulate(dup, five) = four;   // modify dup and copy four struct to dup struct
                                    // should use a const referense to disallow this
    std::cout << "Displaying dup after ill-advised assignment:\n";
    display(dup);
}

void Reference102::display(const FreeThrows& ft)
{
    std::cout
        << "Name: " << ft.name << "\n"
        << "  Made: " << ft.made << "\t"
        << "Attempts: " << ft.attempts << "\t"
        << "Percent: " << ft.percent << "\n";
}

void Reference102::setPercent(FreeThrows& ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f * ft.made / ft.attempts;
    else
        ft.percent = 0;
}

FreeThrows& Reference102::accumulate(FreeThrows& target, const FreeThrows& source)
{
    target.attempts += source.attempts;
    target.made += source.made;
    setPercent(target);
    return target;
}
