//
//  StonewtType03.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 29/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "StonewtType03.hpp"

namespace ClassTypeCasts103
{
    // Construct Stonewt object from double value
    Stonewt::Stonewt(double pounds)
    {
        m_stone = int(pounds) / LbsPerStn;      // integer division
        m_poundsLeft = int(pounds) % LbsPerStn + pounds - int(pounds);  // why not use m_stone?
        m_pounds = pounds;
        
        std::cout << "> C: " << m_pounds << "p\t|  "
                  << m_stone << "s, " << m_poundsLeft << "p\n";
    }
    
    // Construct Stonewt object from stone and pounds values
    Stonewt::Stonewt(int stone, double pounds)
    {
        m_stone = stone;
        m_poundsLeft = pounds;
        m_pounds = stone * LbsPerStn + pounds;
        
        std::cout << "> C: " << m_pounds << "p\t|  "
                  << m_stone << "s, " << m_poundsLeft << "p\n";
    }
    
    // Default constructor with 0 weight
    Stonewt::Stonewt()
    {
        m_stone = m_pounds = m_poundsLeft = 0;
        
        std::cout << "> C: " << m_pounds << "p\t|  "
                  << m_stone << "s, " << m_poundsLeft << "p\n";
    }
    
    // Empty destructor
    Stonewt::~Stonewt()
    {
        std::cout << "> D: " << m_pounds << "p\t|  "
                  << m_stone << "s, " << m_poundsLeft << "p\n";
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
    Stonewt::operator double() const
    {
        return m_pounds;
    }
    
    // 
    Stonewt operator+(const Stonewt& st1, const Stonewt& st2)
    {
        return Stonewt(st1.m_pounds + st2.m_pounds);
    }
}
