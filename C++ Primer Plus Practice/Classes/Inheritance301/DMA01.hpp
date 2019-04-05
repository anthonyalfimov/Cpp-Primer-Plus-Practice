//
//  DMA01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Example of inheritance with dynamic memory allocation (DMA)
//

#ifndef DMA01_hpp
#define DMA01_hpp

#include <iostream>

namespace Inheritance300
{
    //  Base class using DMA
    class BaseDMA
    {
    public:
        BaseDMA(const char* label = "null", int rating = 0);
        BaseDMA(const BaseDMA&);
        
        virtual ~BaseDMA();
        
        BaseDMA& operator=(const BaseDMA&);
        
        const char* getLabel() const { return m_label; }
        friend std::ostream& operator<<(std::ostream& os, const BaseDMA& bd);
        
    private:
        char* m_label;
        int m_rating;
    };
    
    // Derived class without DMA
    //  - uses default destructor
    //  - uses implicit copy constructor
    //  - uses implicit assignment operator
    class LacksDMA : public BaseDMA
    {
    public:
        LacksDMA(const char* label = "null", int rating = 0, const char* colour = "blank");
        LacksDMA(const BaseDMA& bd, const char* colour = "blank");
        
        friend std::ostream& operator<<(std::ostream& os, const LacksDMA& ld);
        
    private:
        static const int c_lenght = 40;
        char m_colour[c_lenght];
    };
    
    // Derived class with DMA
    class HasDMA : public BaseDMA
    {
    public:
        HasDMA(const char* label = "null", int rating = 0, const char* style = "none");
        HasDMA(const BaseDMA& bd, const char* style = "none");
        HasDMA(const HasDMA&);
        
        virtual ~HasDMA();
        
        HasDMA& operator=(const HasDMA&);
        
        friend std::ostream& operator<<(std::ostream& os, const HasDMA& hd);
        
    private:
        char* m_style;
    };
    
}   // end namespace Inheritance300

#endif /* DMA01_hpp */
