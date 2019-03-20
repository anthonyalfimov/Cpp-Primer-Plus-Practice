//
//  BaseClass01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef BaseClass01_hpp
#define BaseClass01_hpp

#include <string>

namespace Inheritance101
{
//  Simple base class
    class TableTennisPlayer
    {
    public:
        TableTennisPlayer(const std::string& fn = "none",
                          const std::string& ln = "none", bool hasTable = false);
        void name() const;
        bool hasTable() const { return m_hasTable; }
        void resetTable(bool hasTable) { m_hasTable = hasTable; }
        
    private:
        std::string m_firstName;
        std::string m_lastName;
        bool m_hasTable;
    };
}   // end namespace Inheritance101

#endif /* BaseClass01_hpp */
