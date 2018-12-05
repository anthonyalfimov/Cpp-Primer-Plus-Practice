//
//  LInkedListType01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 05/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#ifndef LinkedListType01_hpp
#define LinkedListType01_hpp

namespace LinkedList01
{
//  Using typedef as class templates haven't been covered yet
    typedef int Item;
    
    struct Node
    {
        Item data;
        Node* ref;
    };
    
    class List
    {
    public:
    //  Constructors and destructors
        List();         // Create an empty list
        ~List();
        
    //  Methods
        
        /**
         Add a new item to the end of the list
         
         @param item Item to add to the list
         @return False if list is already full, true otherwise
         */
        bool add(const Item& item);
        
        /**
         Determine whether list is empty
         
         @return True if list is empty, false otherwise
         */
        bool isEmpty() const;
        
        /**
         Visit every element of the list and perform operation defined by the passed
         function on it
         
         @param op Function defining the operation to perform on each list item
         */
        void process(void (*op)(Item&));
        
        /**
         Retrieve pointer to list item at given index
         
         @param index Index
         @return nullptr if index if out of bounds, pointer to item at index otherwise
         */
        Item* at(int index);
        
    private:
        // Basic linked list with only head pointer stored
        Node* m_head;
    };
    
    // Keep inline implementations out of the interface for clarity
    inline List::List() { m_head = nullptr; }
    inline bool List::isEmpty() const { return m_head == nullptr; }
}

#endif /* LinkedListType01_hpp */
