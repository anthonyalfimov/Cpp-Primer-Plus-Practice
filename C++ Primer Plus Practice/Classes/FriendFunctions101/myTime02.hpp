//
//  myTime02.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef myTime02_hpp
#define myTime02_hpp

#include <iostream>

namespace FriendFunctions100
{
    class Time
    {
    private:
        int hours;
        int minutes;
        
    public:
//      Constructors
        Time();
        Time(int h, int m = 0);
        
//      Methods
        void addMin(int m);
        void addHr(int h);
        void reset(int h = 0, int m = 0);
        Time operator+(const Time& t) const;    // return by value (Time object will be copied)
        Time operator-(const Time& t) const;
        Time operator*(double n) const;
        
        friend Time operator*(double n, const Time& t)
        { return t * n; }                       // inline definition:
                                                // every time compiler encounters "wrong" order,
                                                //     it will replace it with the "right" one
        friend std::ostream& operator<<(std::ostream& os, const Time& t);
    };
}

#endif /* myTime02_hpp */
