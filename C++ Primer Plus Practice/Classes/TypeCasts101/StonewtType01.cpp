//
//  StonewtType01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 23/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "StonewtType01.hpp"

namespace ClassTypeCasts101
{
    // Construct Stonewt object from double value
    Stonewt::Stonewt(double pounds)
    {
        m_stone = int(pounds) / LbsPerStn;      // integer division
        m_poundsLeft = int(pounds) % LbsPerStn + pounds - int(pounds);  // why not use m_stone?
        m_pounds = pounds;
        
        std::cout << "/C\n";
    }
    
    // Construct Stonewt object from stone and pounds values
    Stonewt::Stonewt(int stone, double pounds)
    {
        m_stone = stone;
        m_poundsLeft = pounds;
        m_pounds = stone * LbsPerStn + pounds;
        
        std::cout << "/C\n";
    }
    
    // Default constructor with 0 weight
    Stonewt::Stonewt()
    {
        m_stone = m_pounds = m_poundsLeft = 0;
        
        std::cout << "/C\n";
    }
    
    // Copy constructor
    Stonewt::Stonewt(const Stonewt& st)
    {
        m_stone = st.m_stone;
        m_poundsLeft = st.m_poundsLeft;
        m_pounds = st.m_pounds;
        
        std::cout << "/CC\n";
    }
    
    // Empty destructor
    Stonewt::~Stonewt()
    {
        std::cout << "/D\n";
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
}
