//
//  Cutomer01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 22/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <cstdlib>
#include "Customer01.hpp"

namespace Queue101
{
    // The random number generation here is seeded only in ATMsim01.cpp, but not in te class itself
    
    void Customer::set(long time)
    {
        m_processTime = std::rand() % 3 + 1;    // set to random value in [1, 3]
        m_arrivalTime = time;
    }
}
