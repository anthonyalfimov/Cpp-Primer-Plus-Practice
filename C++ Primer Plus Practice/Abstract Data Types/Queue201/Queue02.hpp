//
//  Queue02.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 06/11/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Queue02_h
#define Queue02_h

namespace Queue201
{
    template <typename Item>
    class Queue
    {
    public:
        Queue (int size = mQueueSize) : mSize (size) {}
        ~Queue();
        
        // State checks
        bool isEmpty() const { return mCount == 0; }
        bool isFull()  const { return mCount == mSize; }
        int  count()   const { return mCount; }
        
        // Operations
        /**
         Add item to the end of the queue
         
         @param item item to be enqueued
         @return returns true if succesful, false if queue is full
         */
        bool enqueue (const Item& item);
        
        /**
         Remove item from the front of the queue
         
         @param item storage for the dequeued item
         @return returns true if succesful, false if queue is empty
         */
        bool dequeue (Item& item);
        
    private:
//      Class-scope definitions
        static const int mQueueSize = 10;
        
        // Nested class definition local to this class
        class Node
        {
        public:
            Node (const Item& data) : mData (data), mRef (nullptr) {}
            
            // All data members are public so that Queue class can access them
            Item mData;
            Node* mRef;
        };
        
//      Private class members
        Node* mHead = nullptr;      // pointer to the head (front) of the queue
        Node* mTail = nullptr;      // pointer to the tail (back) of the queue
        
        int mCount = 0;             // current number of items in the queue
        const int mSize;            // maximum number of items in the queue
        
//      Disable copy constructor and assignment operator
        Queue (const Queue&) = delete;
        Queue& operator= (const Queue&) = delete;
    };
    
//  Queue methods
    template <typename Item>
    Queue<Item>::~Queue()
    {
        Node* current;
        
        while (mHead != nullptr)
        {
            current = mHead;                    // save current node address
            mHead = mHead->mRef;                // point head to the next node
            delete current;                     // delete current node
        }
    }
    
    template <typename Item>
    bool Queue<Item>::enqueue (const Item& item)
    {
        if (isFull())
            return false;
        
        Node* add = new Node (item);            // on failure, throws std::bad_alloc exception
        
        if (isEmpty())                          // is queue is empty
            mHead = add;                        // - place item in head
        else
            mTail->mRef = add;                  // - else place at the tail
        
        mTail = add;                            // save new tail node
        mCount++;                               // increment number of items in the queue
        
        return true;
    }
    
    template <typename Item>
    bool Queue<Item>::dequeue (Item& item)
    {
        if (isEmpty())
            return false;
        
        item = mHead->mData;                    // return the data from the head node
        Node* first = mHead;                    // save location of the first item
        mHead = mHead->mRef;                    // reset head to the next node
        delete first;                           // deallocate former first item
        mCount--;                               // decrement number of items in the queue
        
        if (isEmpty())                          // if deleted last item, set tail to null
            mTail = nullptr;
        
        return true;
    }
}   // end namespace Queue201

#endif /* Queue02_h */
