//
//  Queue01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 22/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Queue01_hpp
#define Queue01_hpp

#include "Customer01.hpp"

namespace Queue101
{
    typedef Customer Item;      // use typedef until class templates are discussed
    
    class Queue
    {
    private:
//      Class-scope definitions
        // Nested structure definition local to this class
        struct Node
        {
            Item data;
            Node* ref;
        };
        
        static const int Q_SIZE = 10;
        
//      Private class members
        Node* m_head;           // pointer to the head (front) of the queue
        Node* m_tail;           // pointer to the tail (back) of the queue
        
        int m_count = 0;        // current number of items in the queue (with default init value)
        const int m_size;       // maximum number of items in the queue
        
//      Dummy definitions to disable copying and assignment
        Queue(const Queue& q) : m_size(0) {}
        Queue& operator=(const Queue& q) { return *this; }
        
    public:
        Queue(int size = Q_SIZE);
        ~Queue();
        
        // State checks
        bool isEmpty() const { return m_count == 0; }
        bool isFull()  const { return m_count == m_size; }
        int  count()   const { return m_count; }
        
        // Operations
        /**
         Add item to the end of the queue

         @param item item to be enqueued
         @return returns true if succesful, false if queue is full
         */
        bool enqueue(const Item& item);
        
        /**
         Remove item from the front of the queue

         @param item storage for the dequeued item
         @return returns true if succesful, false if queue is empty
         */
        bool dequeue(Item& item);
    };
}

#endif /* Queue01_hpp */
