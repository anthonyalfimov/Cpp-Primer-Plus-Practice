//
//  myTime01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 10/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef myTime01_hpp
#define myTime01_hpp

namespace OpOverload101
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
        void show();
    };
}

#endif /* myTime01_hpp */
