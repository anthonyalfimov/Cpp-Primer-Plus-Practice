//
//  StonewtType03.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 29/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef StonewtType03_hpp
#define StonewtType03_hpp

namespace ClassTypeCasts103
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
        ~Stonewt();                             // destructor
        
        void showPounds() const;                // show weight in pounds format
        void showStone() const;                 // show weight in stone and pounds format
        
        // Conversion fucntions
        //     if this wasn't explicit, resolving addition with type double would be ambiguous
        explicit operator double() const;          // convert only using explicit type cast
        
        // Addition function - using a friend so both operands can use implicit type casts
        friend Stonewt operator+(const Stonewt&, const Stonewt&);
    };
}

#endif /* StonewtType03_hpp */
