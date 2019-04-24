//
//  Student02.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 23/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include "Student02.hpp"

namespace Inheritance400
{
    //  Public methods
    double Student::average() const
    {
        if (ArrayDouble::size() > 0)
            return ArrayDouble::sum() / ArrayDouble::size();
        else
            return 0;
    }
    
    const std::string& Student::name() const
    {
        return (const std::string&) *this;          // type cast the object to the string base class
    }
    
    double& Student::operator[](int i)
    {
        return ArrayDouble::operator[](i);          // use std::valarray<double>::operator[]()
    }
    
    double  Student::operator[](int i) const
    {
        return ArrayDouble::operator[](i);
    }
    
    //  Friend functions
    std::istream& operator>>(std::istream& is, Student& s)
    {
        is >> (std::string&) s;                     // use std::string version of operator>>()
        return is;
    }
    
    std::istream& getline(std::istream& is, Student& s)
    {
        getline(is, (std::string&) s);              // use std::string friend version of getline()
        return is;
    }
    
    std::ostream& operator<<(std::ostream& os, const Student& s)
    {
        os << "Scores for "
           << (const std::string&) s << ":\n";      // use std::string version of operator<<()
        s.outputScores(os);
        return os;
    }
    
    //  Private methods
    std::ostream& Student::outputScores(std::ostream& os) const
    {
        int i;
        int size = static_cast<int>(ArrayDouble::size());
        
        if (size > 0)
        {
            for (i = 0; i < size; i++)
            {
                os << ArrayDouble::operator[](i) << " ";
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
}   // end namespace Inheritance400

