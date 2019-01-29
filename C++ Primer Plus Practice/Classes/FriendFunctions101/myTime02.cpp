//
//  myTime02.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include "myTime02.hpp"

namespace FriendFunctions100
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
    
    Time Time::operator+(const Time& t) const     // return type can't be a reference here
    {
        Time sum;
        sum.minutes = minutes + t.minutes;
        sum.hours = hours + t.hours + sum.minutes / 60;
        sum.minutes %= 60;
        return sum;             // return by value because sum is scoped to this function
    }
    
    Time Time::operator-(const Time& t) const
    {
        // How do we deal with negative results?
        Time diff;
        int this_total, t_total;
        this_total =   minutes + 60 *   hours;
        t_total    = t.minutes + 60 * t.hours;
        
        diff.minutes = (this_total - t_total) % 60;
        diff.hours   = (this_total - t_total) / 60;
        
        return diff;
    }
    
    Time Time::operator*(double n) const
    {
        Time result;
        long total = n * (minutes + 60 * hours);
        result.minutes = total % 60;        // implicit conversion can't lead to loss of precision
        result.hours   = static_cast<int>(total / 60);
        
        return result;
    }
    
    std::ostream& operator<<(std::ostream& os, const Time& t)
    {
        os << t.hours << " hours, " << t.minutes << " minutes";
        return os;
    }
}
