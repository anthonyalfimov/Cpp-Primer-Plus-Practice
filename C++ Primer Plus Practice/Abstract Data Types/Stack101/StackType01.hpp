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
     Check wether stack is empty

     @return True is stack is empty, False otherwise
     */
    bool isEmpty() const;
    
    /**
     Check wether stack is full

     @return True is stack is full, False otherwise
     */
    bool isFull()  const;
    
    /**
     Add item to the stack

     @param item Item to add to the stack
     @return False if stack is already full, True otherwise
     */
    bool push(const Item& item);
    
    /**
     Pop top of the stack into the passed item

     @param item Item to pop top of the stack into
     @return False if the stack is already empty, True otherwise
     */
    bool pop(Item& item);
};

#endif /* StackType01_hpp */
