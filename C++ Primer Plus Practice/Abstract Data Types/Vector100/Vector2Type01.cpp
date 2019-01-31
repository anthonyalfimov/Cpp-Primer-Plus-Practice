//
//  Vector2Type01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 13/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <cmath>
#include "Vector2Type01.hpp"

namespace Vector100
{
//  Calculate degrees in one radian (~57.3)
    const double radToDeg {45.0 / std::atan(1.0)};
    
//  Private methods
    
    // Calculate polar coordinates from rect
    void Vector2::setR()
    {
        m_R = std::sqrt(m_X * m_X + m_Y * m_Y);
    }
    
    void Vector2::setAng()
    {
        if (m_X == 0.0 && m_Y == 0.0)
            m_Ang = 0.0;
        else
            m_Ang = std::atan2(m_Y, m_X);
    }
    
    // Calculate rect coordinates from polar
    void Vector2::setX()
    {
        m_X = m_R * std::cos(m_Ang);
    }
    
    void Vector2::setY()
    {
        m_Y = m_R * std::sin(m_Ang);
    }
    
//  Public methods
    
    // Default constructor
    Vector2::Vector2()
    {
        m_X = m_Y = m_R = m_Ang = 0.0;
        m_Mode = RECT;
    }
    
    // Construct vector from 2 parameters that are interpreted as rect (default)
    //     or polar coordinates depending on the specified mode
    Vector2::Vector2(double p1, double p2, Mode mode)       // note that enum is accesible here!
    {
        reset(p1, p2, mode);
    }
    
    // Destructor
    Vector2::~Vector2()
    {
        
    }
    
    void Vector2::reset(double p1, double p2, Mode mode)
    {
        m_Mode = mode;
        if (mode == RECT)
        {
            // Set rect coords from parameter values
            m_X = p1;
            m_Y = p2;
            // Calculate polar coords
            setR();
            setAng();
        }
        else if (mode == POL)
        {
            // Set polar coords from parameter values
            m_R = p1;
            m_Ang = p2 / radToDeg;
            // Calculate rect coords
            setX();
            setY();
        }
        else
        {
            std::cout << "Incorrect 3rd argument to Vector2() -- "
            "vector set to 0\n";
            
            m_X = m_Y = m_R = m_Ang = 0.0;
            m_Mode = RECT;
        }
    }
    
    // Mode setters
    void Vector2::polarMode()
    {
        m_Mode = POL;
    }
    
    void Vector2::rectMode()
    {
        m_Mode = RECT;
    }
    
    // Operator overloading
    Vector2 Vector2::operator+(const Vector2& v) const
    {
        return Vector2(m_X + v.m_X, m_Y + v.m_Y);
    }
    
    Vector2 Vector2::operator-(const Vector2& v) const
    {
        return Vector2(m_X - v.m_X, m_Y - v.m_Y);
    }
    
    Vector2 Vector2::operator-() const
    {
        return Vector2(-m_X, -m_Y);
    }
    
    Vector2 Vector2::operator*(double n) const
    {
        return Vector2(n * m_X, n * m_Y);
    }
    
//  Friend functions
    std::ostream& operator<<(std::ostream& os, const Vector2& v)
    {
        if (v.m_Mode == Vector2::RECT)  // note that enum is not accesible here without specifier!
            os << "(x,y) = (" << v.m_X << ", " << v.m_Y << ")";
        else if (v.m_Mode == Vector2::POL)
            os << "(r,a) = (" << v.m_R << ", " << v.m_Ang * radToDeg << ")";
        else
            // should never be reached, but better to futureproof
            os << "Vector object mode invalid";
            
        return os;
    }
}   // end namespace Vector100
