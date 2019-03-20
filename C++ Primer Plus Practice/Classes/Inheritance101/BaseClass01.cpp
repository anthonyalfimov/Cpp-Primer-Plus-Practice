//
//  BaseClass01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "BaseClass01.hpp"

namespace Inheritance101
{
//  Avoid invoking std::string default constructor followed by operator= by using member init. list
    TableTennisPlayer::TableTennisPlayer(const std::string& fn,
                                         const std::string& ln,
                                         bool ht) : m_firstName(fn),
                                                    m_lastName(ln),
                                                    m_hasTable(ht) {}
    
    void TableTennisPlayer::name() const
    {
        std::cout << m_lastName << ", " << m_firstName;
    }
}   // end namespace Inheritance101
