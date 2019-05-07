//
//  ArrayType01.h
//  C++ Primer Plus Practice
//
//  Created by Anthony on 07/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef ArrayType01_h
#define ArrayType01_h

#include <iostream>
#include <cstdlib>

namespace ClassTemplates201
{
    template <typename T, int t_size>
    class Array
    {
    public:
        Array() {}
        explicit Array(const T& value);         // pass initial value assigned to all elements
        
        virtual T& operator[](int i);
        virtual T operator[](int i) const;
        
    private:
        T m_elements[t_size];
    };
    
    template <typename T, int t_size>
    Array<T, t_size>::Array(const T& value)
    {
        for (int i = 0; i < t_size; i++)
            m_elements[i] = value;
    }
    
    template <typename T, int t_size>
    T& Array<T, t_size>::operator[](int i)
    {
        if (i < 0 || i >= t_size)               // bounds check
        {
            std::cerr << "Array index " << i << " out of bounds\n";
            std::exit(EXIT_FAILURE);
        }
        
        return m_elements[i];
    }
    
    template <typename T, int t_size>
    T Array<T, t_size>::operator[](int i) const
    {
        if (i < 0 || i >= t_size)               // bounds check
        {
            std::cerr << "Array index " << i << " out of bounds\n";
            std::exit(EXIT_FAILURE);
        }
        
        return m_elements[i];
    }
}   // end namespace ClassTemplates201

#endif /* ArrayType01_h */
