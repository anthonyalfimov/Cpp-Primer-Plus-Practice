//
//  Vector2Type01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 13/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef Vector2Type01_hpp
#define Vector2Type01_hpp

#include <iostream>

namespace Vector100
{
    class Vector2
    {
    public:
        // RECT for rectangular, POL for polar modes
        enum Mode {RECT, POL};
        
    private:
        // Rectangular representation
        double m_X;
        double m_Y;
        
        // Polar representation
        double m_R;     // radial coordinate
        double m_Ang;   // angular coordinate
        
        // State member
        Mode m_Mode;    // RECT or POL
        
        // Private methods to set the values
        void setX();
        void setY();
        void setR();
        void setAng();
        
    public:
        Vector2();
        Vector2(double p1, double p2, Mode mode = RECT);
        ~Vector2();
        
        /**
         Reset vector from 2 parameters that are interpreted as rect (default)
         or polar coordinates depending on the specified mode

         @param p1 X or R
         @param p2 Y or Angle
         @param mode RECT or POL
         */
        void reset(double p1 = 0.0, double p2 = 0.0, Mode mode = RECT);
        
        // Getters
        double getX()   const { return m_X; }
        double getY()   const { return m_Y; }
        double getR()   const { return m_R; }
        double getAng() const { return m_Ang; }
        
        // Mode setters
        void polarMode();   // set polar mode
        void rectMode();    // set rect mode
        
        // Operator overloading
        
        /**
         Add Vector2s
         */
        Vector2 operator+(const Vector2& v) const;
        
        /**
         Subtract Vector2s
         */
        Vector2 operator-(const Vector2& v) const;
        
        /**
         Inverse sign of Vector2
         */
        Vector2 operator-() const;
        
        /**
         Multiply Vector2 by a scalar
         */
        Vector2 operator*(double n) const;
        
        // Operator overloading - Friends
        friend Vector2 operator*(double n, const Vector2& v) { return v * n; }  // inline definition
        
        /**
         Display rect coordinates if mode is RECT or polar coordinates if mode is POL

         @param os std::ostream output stream
         @param v Vector2 object to display
         @return reference to std::ostream output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
    };
}   // end namespace Vector101

#endif /* Vector2Type01_hpp */
