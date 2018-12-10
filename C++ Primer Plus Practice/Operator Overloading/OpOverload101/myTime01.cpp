//
//  myTime01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 10/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "myTime01.hpp"

namespace OpOverload101
{
    Time::Time()
    {
        hours = minutes = 0;
    }
    
    Time::Time(int h, int m)
    {
        hours = h;
        minutes = m;
    }
    
    void Time::addMin(int m)
    {
        minutes += m;
        hours += minutes / 60;
        minutes %= 60;
    }
    
    void Time::addHr(int h)
    {
        hours += h;
    }
    
    void Time::reset(int h, int m)
    {
        hours = h;
        minutes = m;
    }
    
    Time Time::sum(const Time& t) const     // return type can't be a reference here
    {
        Time sum;
        sum.minutes = minutes + t.minutes;
        sum.hours = hours + t.hours + sum.minutes / 60;
        sum.minutes %= 60;
        return sum;             // return by value because sum is scoped to this function
    }
    
    void Time::show() {
        std::cout << hours << " hours, " << minutes << " minutes";
    }
    
    
    
    
}
