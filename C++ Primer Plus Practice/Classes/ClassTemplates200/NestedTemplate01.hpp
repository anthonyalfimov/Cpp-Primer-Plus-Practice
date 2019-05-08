//
//  NestedTemplate01.h
//  C++ Primer Plus Practice
//
//  Created by Anthony on 08/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef NestedTemplate01_h
#define NestedTemplate01_h

namespace ClassTemplates203
{
    template <typename Q>
    class Beta
    {
    public:
        Beta(Q quality, int number) : m_quality(quality), m_number(number) {}
        
        template <typename T>           // template method declaration, defined outside class body
        T calculate(T factor, Q divisor);
        
        void show() const { m_quality.show(); m_number.show(); }
        
    private:
        template <typename V>           // private nested template class member declaration
        class Hold;                     // can be also defined inline
        
        Hold<Q>   m_quality;            // use private template to create objects
        Hold<int> m_number;
    };
    
    // member class definition
    template <typename Q>
        template <typename V>
        class Beta<Q>::Hold
        {
        public:
            Hold(V value) : m_value(value) {}
            void show() const { std::cout << m_value << "\n"; }
            V value() const { return m_value; }
            
        private:
            V m_value;
        };
    
    // member funtion definition
    template <typename Q>
        template <typename T>
        T Beta<Q>::calculate(T factor, Q divisor)
        {
            return (m_quality.value() + m_number.value()) * factor / divisor;
        }
}

#endif /* NestedTemplate01_h */
