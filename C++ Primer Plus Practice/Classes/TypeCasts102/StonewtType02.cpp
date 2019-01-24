//
//  StonewtType02.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 24/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "StonewtType02.hpp"

namespace ClassTypeCasts102
{
    // Construct Stonewt object from double value
    Stonewt::Stonewt(double pounds)
    {
        m_stone = int(pounds) / LbsPerStn;      // integer division
        m_poundsLeft = int(pounds) % LbsPerStn + pounds - int(pounds);  // why not use m_stone?
        m_pounds = pounds;
    }
    
    // Construct Stonewt object from stone and pounds values
    Stonewt::Stonewt(int stone, double pounds)
    {
        m_stone = stone;
        m_poundsLeft = pounds;
        m_pounds = stone * LbsPerStn + pounds;
    }
    
    // Default constructor with 0 weight
    Stonewt::Stonewt()
    {
        m_stone = m_pounds = m_poundsLeft = 0;
    }
    
    // Empty destructor
    Stonewt::~Stonewt()
    {
        
    }
    
    /**
     Show weight in stone and pounds
     */
    void Stonewt::showStone() const
    {
        std::cout << m_stone << " stone, " << m_poundsLeft << " pounds\n";
    }
    
    /**
     Show weight in pounds
     */
    void Stonewt::showPounds() const
    {
        std::cout << m_pounds << " pounds\n";
    }
    
//  Conversion functions
    Stonewt::operator int() const
    {
        // rounding instead of truncating
        return int (m_pounds + 0.5);            // conversion functions uses return statement
    }
    
    Stonewt::operator double() const
    {
        return m_pounds;
    }
}

