//
//  PairType01.h
//  C++ Primer Plus Practice
//
//  Created by Anthony on 07/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef PairType01_h
#define PairType01_h

namespace ClassTemplates202
{
    template <typename T1, typename T2>
    class Pair
    {
    public:
        Pair() {}
        Pair(const T1& a, const T2& b) : m_a(a), m_b(b) {}
        
        T1& first();
        T2& second();
        T1 first()  const { return m_a; }
        T2 second() const { return m_b; }
        
    private:
        T1 m_a;
        T2 m_b;
    };
    
    template <typename T1, typename T2>
    T1& Pair<T1, T2>::first()
    {
        return m_a;
    }
    
    template <typename T1, typename T2>
    T2& Pair<T1, T2>::second()
    {
        return m_b;
    }
}   // end namespace ClassTemplates202

#endif /* PairType01_h */
