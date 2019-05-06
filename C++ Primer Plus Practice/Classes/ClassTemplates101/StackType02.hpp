//
//  StackType02.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 06/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef StackType02_h
#define StackType02_h

namespace ClassTemplates100
{
    template <typename Type>
    class Stack
    {
    public:
        Stack(): m_top(0) {}
        
        bool isEmpty() const;
        bool isFull() const;
        bool push(const Type& item);        // add item to stack
        bool pop(Type& item);               // pop top into item
        
    private:
        static const int c_max = 10;        // stack size
        Type m_items[c_max];                // stack items
        int m_top;                          // index for top stack item
    };
    
    template <typename Type>
    bool Stack<Type>::isEmpty() const
    {
        return m_top == 0;
    }
    
    template <typename Type>
    bool Stack<Type>::isFull() const
    {
        return m_top == c_max;
    }
    
    template <typename Type>
    bool Stack<Type>::push(const Type& item)
    {
        if (m_top < c_max)
        {
            m_items[m_top] = item;          // add new item to the top
            m_top++;                        // point top to the next spot on the stack
            return true;
        }
        
        return false;
    }
    
    template <typename Type>
    bool Stack<Type>::pop(Type& item)
    {
        if (m_top > 0)
        {
            m_top--;                        // point top to the last item on the stack
            item = m_items[m_top];          // fetch item from the top of stack
            return true;
        }
        
        return false;
    }
    
    
}   // end namespace ClassTemplates100
#endif /* StackType02_h */
