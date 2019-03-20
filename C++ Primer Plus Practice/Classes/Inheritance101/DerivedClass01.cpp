//
//  DerivedClass01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 20/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include "DerivedClass01.hpp"

namespace Inheritance101
{
    RatedPlayer::RatedPlayer(unsigned int r, const std::string& fn, const std::string& ln, bool ht)
        : TableTennisPlayer(fn, ln, ht)         // base class constructor is always executed first
    {
        m_rating = r;
    }
    
    RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp)
        : TableTennisPlayer(tp), m_rating(r)
    {
    }
}   // end namespace Inheritance101
