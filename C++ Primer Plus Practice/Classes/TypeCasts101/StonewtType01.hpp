//
//  StonewtType01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 23/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef StonewtType01_hpp
#define StonewtType01_hpp

namespace ClassTypeCasts101
{
    class Stonewt
    {
    private:
        static const int LbsPerStn = 14;        // pounds per stone
        
        int    m_stone;                         // whole stones
        double m_poundsLeft;                    // fractional pounds
        double m_pounds;                        // entire weight in pounds
        
    public:
        Stonewt(double pounds);                 // constructor for fractional pounds
        Stonewt(int stone, double pounds);      // constructor for stone and pounds
        Stonewt();                              // default constructor
        Stonewt(const Stonewt&);                // copy constructor
        ~Stonewt();                             // destructor
        
        void showPounds() const;                // show weight in pounds format
        void showStone() const;                 // show weight in stone and pounds format
    };
}

#endif /* StonewtType01_hpp */
