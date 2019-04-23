//
//  DMA01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Example of inheritance with dynamic memory allocation (DMA)
//

#include <cstring>
#include "DMA01.hpp"

namespace Inheritance300
{
    // BaseDMA methods
    BaseDMA::BaseDMA(const char* label, int rating)
    {
        m_label = new char[std::strlen(label) + 1];
        std::strcpy(m_label, label);
        m_rating = rating;
        
        std::cout << "|> BaseDMA constructor for "  << m_label << "\n";
    }
    
    BaseDMA::BaseDMA(const BaseDMA& bd)
    {
        m_label = new char[std::strlen(bd.m_label) + 1];
        std::strcpy(m_label, bd.m_label);
        m_rating = bd.m_rating;
        
        std::cout << "|> BaseDMA copy constructor for "  << m_label << "\n";
    }
    
    BaseDMA::~BaseDMA()
    {
        std::cout << "|> BaseDMA destructor for "  << m_label << "... ";
        delete [] m_label;
        std::cout << "Done.\n";
    }
    
    BaseDMA& BaseDMA::operator=(const BaseDMA& bd)
    {
        if (this == & bd)       // prevent self-copying
            return *this;
        
        delete [] m_label;      // delete old contents
        m_label = new char[std::strlen(bd.m_label) + 1];
        std::strcpy(m_label, bd.m_label);
        m_rating = bd.m_rating;
        
        std::cout << "|> BaseDMA assingment for "  << m_label << "\n";
        
        return *this;
    }
    
    std::ostream& operator<<(std::ostream& os, const BaseDMA& bd)
    {
        os << "Label: " << bd.m_label << "\n";
        os << "Rating: " << bd.m_rating << "\n";
        return os;
    }
    
    // LacksDMA methods
    LacksDMA::LacksDMA(const char* label, int rating, const char* colour) : BaseDMA(label, rating)
    {
        std::strncpy(m_colour, colour, c_lenght - 1);
        m_colour[c_lenght - 1] = '\0';
        
        std::cout << "|> LacksDMA constructor for "  << getLabel() << "\n";
    }
    
    LacksDMA::LacksDMA(const BaseDMA& bd, const char* colour) : BaseDMA(bd)
    {
        std::strncpy(m_colour, colour, c_lenght - 1);
        m_colour[c_lenght - 1] = '\0';
        
        std::cout << "|> LacksDMA constructor for "  << getLabel() << "\n";
    }
    
    // Define derived class friend function to specialise its functionality.
    //     Otherwise, base-class friend could be used with dervied object upcasted to base class
    std::ostream& operator<<(std::ostream& os, const LacksDMA& ld)
    {
        os << (const BaseDMA&) ld;      // cast to base-class type to use its friend
        os << "Colour: " << ld.m_colour << "\n";
        return os;
    }
    
    // HasDMA methods
    HasDMA::HasDMA(const char* label, int rating, const char* style)
        : BaseDMA(label, rating)
    {
        m_style = new char[std::strlen(style) + 1];
        std::strcpy(m_style, style);
        
        std::cout << "|> HasDMA constructor for "  << getLabel() << "\n";
    }
    
    HasDMA::HasDMA(const BaseDMA& bd, const char* style) : BaseDMA(bd)
    {
        m_style = new char[std::strlen(style) + 1];
        std::strcpy(m_style, style);
        
        std::cout << "|> HasDMA constructor for "  << getLabel() << "\n";
    }
    
    HasDMA::HasDMA(const HasDMA& hd) : BaseDMA(hd)      // invoke base-class copy constructor
    {
        m_style = new char[std::strlen(hd.m_style) + 1];
        std::strcpy(m_style, hd.m_style);
        
        std::cout << "|> HasDMA copy constructor for "  << getLabel() << "\n";
    }
    
    HasDMA::~HasDMA()           // base-class destructor called automatically
    {
        std::cout << "|> HasDMA destructor for "  << getLabel() << "... ";
        
        delete [] m_style;      // only handle memory dynamically allocated in derived class
        
        std::cout << "Done.\n";
    }
    
    HasDMA& HasDMA::operator=(const HasDMA& hd)
    {
        if (this == & hd)       // prevent self-copying
            return * this;
        
        BaseDMA::operator=(hd); // call base-class assignment to assign base-class component
        
        delete [] m_style;      // delete old data
        m_style = new char[std::strlen(hd.m_style) + 1];
        std::strcpy(m_style, hd.m_style);
        
        std::cout << "|> HasDMA assignment for "  << getLabel() << "\n";
        
        return *this;
    }
    
    // Define derived class friend function to specialise its functionality.
    //     Otherwise, base-class friend could be used with dervied object upcasted to base class
    std::ostream& operator<<(std::ostream& os, const HasDMA& hd)
    {
        os << (const BaseDMA&) hd;      // cast to base-class type to use its friend
        os << "Style: " << hd.m_style << "\n";
        return os;
    }
    
}   // end namespace Inheritance300
