//
//  StackType03.h
//  C++ Primer Plus Practice
//
//  Created by Anthony on 06/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Class template example with dynamic memory allocation
//

#ifndef StackType03_h
#define StackType03_h

namespace ClassTemplates102
{
    template <typename Type>
    class Stack
    {
    public:
        explicit Stack(int size = c_size);
        Stack(const Stack&);
        
        ~Stack() { delete [] m_items; }
        
        bool isEmpty() const { return m_top == 0; }
        bool isFull()  const { return m_top == m_stackSize; }
        bool push(const Type& item);        // add item to stack
        bool pop(Type& item);               // pop top into item
        
        Stack& operator=(const Stack&);
        
    private:
        static const int c_size = 10;       // default stack size
        int   m_stackSize;                  // actual stack size
        Type* m_items;                      // pointer to stack items
        int   m_top;                        // index for top stack item
    };
    
    template <typename Type>
    Stack<Type>::Stack(int size) : m_stackSize(size), m_top(0)
    {
        m_items = new Type[m_stackSize];
    }
    
    template <typename Type>
    Stack<Type>::Stack(const Stack& st)
    {
        m_stackSize = st.m_stackSize;
        m_top = st.m_top;
        m_items = new Type[m_stackSize];
        
        for (int i = 0; i < m_top; i++)
            m_items[i] = st.m_items[i];
    }
    
    template <typename Type>
    bool Stack<Type>::push(const Type& item)
    {
        if (m_top < m_stackSize)
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
    
    template <typename Type>
    Stack<Type>& Stack<Type>::operator=(const Stack& st)    // have to use `Stack<Type>` outside class scope
    {
        if (this == *st)
            return *this;
        
        delete [] m_items;
        m_stackSize = st.m_stackSize;
        m_top = st.m_top;
        m_items = new Type[m_stackSize];
        
        for (int i = 0; i < m_top; i++)
            m_items[i] = st.m_items[i];
        
        return * this;
    }
}   // end namespace ClassTemplates102

#endif /* StackType03_h */
