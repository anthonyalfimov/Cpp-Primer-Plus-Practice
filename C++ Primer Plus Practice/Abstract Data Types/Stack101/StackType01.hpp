//
//  StackType01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 29/11/2018.
//
//  Simplified stack data type implementation
//

#ifndef StackType01_hpp
#define StackType01_hpp

// Placeholder to be replaced with a template

namespace Stack01
{
    typedef unsigned long Item;

    class Stack
    {
    private:
        static const int MAX {10};      // constant specific to the class
        Item items[MAX];                // use an array to hold items
        int top;                        // index for top stack item
        
    public:
        Stack();
        
        /**
         @return true if stack is empty, false otherwise
         */
        bool isEmpty() const;
        
        /**
         @return true if stack is full, false otherwise
         */
        bool isFull()  const;
        
        /**
         Add item to the stack

         @param item Item to add to the stack
         @return false if stack is already full, true otherwise
         */
        bool push(const Item& item);
        
        /**
         Pop top of the stack into the passed item

         @param item Item to pop top of the stack into
         @return false if the stack is already empty, true otherwise
         */
        bool pop(Item& item);
    };
}
    
#endif /* StackType01_hpp */
