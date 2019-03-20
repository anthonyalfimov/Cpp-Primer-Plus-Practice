//
//  DerivedClass01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 20/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef DerivedClass01_hpp
#define DerivedClass01_hpp

#include "BaseClass01.hpp"

namespace Inheritance101
{
    // Simple derived class
    class RatedPlayer : public TableTennisPlayer
    {
    public:
        RatedPlayer(unsigned int rating = 0,
                    const std::string& firstName = "none",
                    const std::string& lastName  = "none", bool hasTable = false);
        RatedPlayer(unsigned int rating, const TableTennisPlayer& tp);
        
        unsigned int rating() const { return m_rating; }
        void resetRating(unsigned int rating) { m_rating = rating; }
        
    private:
        unsigned int m_rating;
    };
}   // end namespace Inheritance101

#endif /* DerivedClass01_hpp */
