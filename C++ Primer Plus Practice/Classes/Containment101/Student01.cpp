//
//  Student01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 17/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include "Student01.hpp"

namespace Containment100
{
//  Public methods
    double Student::average() const
    {
        if (m_scores.size() > 0)
            return m_scores.sum() / m_scores.size();
        else
            return 0;
    }
    
    const std::string& Student::name() const
    {
        return m_name;
    }

    double& Student::operator[](int i)
    {
        return m_scores[i];                         // use std::valarray<double>::operator[]()
    }
    
    double  Student::operator[](int i) const
    {
        return m_scores[i];
    }
    
    std::istream& operator>>(std::istream& is, Student& s)
    {
        is >> s.m_name;                             // use std::string version of operator>>()
        return is;
    }
    
    std::istream& getline(std::istream& is, Student& s)
    {
        getline(is, s.m_name);                      // use std::string version of getline()
        return is;
    }
    
    std::ostream& operator<<(std::ostream& os, const Student& s)
    {
        os << "Scores for " << s.m_name << ":\n";   // use std::string version of operator<<()
        s.outputScores(os);
        return os;
    }

//  Private methods
    std::ostream& Student::outputScores(std::ostream& os) const
    {
        int i;
        int size = static_cast<int>(m_scores.size());
        
        if (size > 0)
        {
            for (i = 0; i < size; i++)
            {
                os << m_scores[i] << " ";
                if (i % 5 == 4)                     // newline after every 5 scores
                    os << "\n";
            }
            
            if (i % 5 != 0)                         // if didn't end on a newline, print one
                os << "\n";
        }
        
        else
            os << " empty array ";
        
        return os;
    }    
}   // end namespace Containment100
