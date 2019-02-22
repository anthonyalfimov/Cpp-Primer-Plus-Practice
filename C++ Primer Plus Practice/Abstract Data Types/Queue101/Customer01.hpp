//
//  Cutomer01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 22/02/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Customer01_hpp
#define Customer01_hpp

namespace Queue101
{
    class Customer
    {
    private:
        long m_arrivalTime;       // arrival time for the customer
        int  m_processTime;       // processing time for the customer
    public:
        Customer() : m_arrivalTime(0), m_processTime(0) {}  // Default constructor
        
        /**
         Sets customer arrival time to the passed value and randomly generates
         processing time in the range [1, 3]
         
         @param arrivalTime time at which the customer arrives
         */
        void set(long arrivalTime);
        
//      Getters
        long getArrivalTime() const { return m_arrivalTime; }
        int  getProcessTime() const { return m_processTime; }
    };
}

#endif /* Customer01_hpp */
