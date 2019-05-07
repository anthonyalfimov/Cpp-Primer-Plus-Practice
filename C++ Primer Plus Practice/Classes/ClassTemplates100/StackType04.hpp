//
//  StackType04.h
//  C++ Primer Plus Practice
//
//  Created by Anthony on 07/05/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//
//  Partial specialisation demonstation version of Stack
//

#ifndef StackType04_h
#define StackType04_h

#include <iostream>
#include <cstring>

namespace ClassTemplates103
{
//  Class template:
    
    template <typename T, int t_size = 5>
    class Stack
    {
    public:
        Stack() : m_top(0) { std::cout << "General template\n"; }
        
        bool isEmpty() const { return m_top == 0; }
        bool isFull()  const { return m_top == t_size; }
        bool push(const T& item);           // add item to stack
        bool pop(T& item);                  // pop top into item
        
    private:
        T m_items[t_size];                  // stack items
        int m_top;                          // index for top stack item
    };

    template <typename T, int t_size>
    bool Stack<T, t_size>::push(const T& item)
    {
        if (m_top < t_size)
        {
            m_items[m_top] = item;          // add new item to the top
            m_top++;                        // point top to the next spot on the stack
            return true;
        }
        
        return false;
    }
    
    template <typename T, int t_size>
    bool Stack<T, t_size>::pop(T& item)
    {
        if (m_top > 0)
        {
            m_top--;                        // point top to the last item on the stack
            item = m_items[m_top];          // fetch item from the top of stack
            return true;
        }
        
        return false;
    }
    
//  Partial specialisation for type `char*`
    
    template <int t_size>
    class Stack<char*, t_size>
    {
    public:
        Stack() : m_top(0) { std::cout << "C-string template\n"; }
        Stack(const Stack&);
        
        ~Stack();
        
        bool isEmpty() const { return m_top == 0; }
        bool isFull()  const { return m_top == t_size; }
        bool push(const char* inString);         // add string to stack
        bool pop(char* outString, int size);     // pop top into item
        
    private:
        char* m_items[t_size];                  // stack items
        int m_top;                              // index for top stack item
        Stack& operator=(const Stack& st) {}    // disable assignment
    };
    
    template <int t_size>
    Stack<char*, t_size>::Stack(const Stack& st)
    {
        for (int i = 0; i < m_top; i++)
            delete [] m_items[i];
        
        m_top = st.m_top;
        
        for (int i = 0; i < m_top; i++)
        {
            m_items[i] = new char[std::strlen(st.m_items[i]) + 1];
            std::strcpy(m_items[i], st.m_items[i]);
        }
    }
    
    template <int t_size>
    Stack<char*, t_size>::~Stack()
    {
        for (int i = 0; i < m_top; i++)
            delete [] m_items[i];
    }
    
    template <int t_size>
    bool Stack<char*, t_size>::push(const char* inString)
    {
        if (m_top < t_size)
        {
            m_items[m_top] = new char[std::strlen(inString) + 1];
            std::strcpy(m_items[m_top], inString);
            
            m_top++;                        // point top to the next spot on the stack
            return true;
        }
        
        return false;
    }
    
    template <int t_size>
    bool Stack<char*, t_size>::pop(char* outString, int size)
    {
        if (m_top > 0)
        {
            m_top--;                        // point top to the last item on the stack
            
            std::strncpy(outString, m_items[m_top], size);
            outString[size - 1] = '\0';
            delete [] m_items[m_top];
            
            return true;
        }
        
        return false;
    }
    
//  Partial specialisation for t_size = 0
    
    template <typename T>
    class Stack<T, 0>
    {
    public:
        Stack() { std::cout << "Empty stack template\n"; }
        
        bool isEmpty() const { return false; }
        bool isFull()  const { return true; }
        bool push(const T& item) { return false; }
        bool pop(T& item)        { return false; }
    };
    
}   // end namespace ClassTemplates103

#endif /* StackType04_h */
