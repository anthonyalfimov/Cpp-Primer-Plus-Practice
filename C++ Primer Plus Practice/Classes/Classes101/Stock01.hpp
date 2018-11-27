//
//  Stock00.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 21/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//
//  Version 01

#ifndef STOCK01_H_
#define STOCK01_H_

#include <string>

namespace Classes101
{
    class Stock             // class declaration
    {
    private:
        std::string company;
        long shares;
        double shareValue;
        double totalValue;
        
//      Methods defined in class declaration are inline:
        void setTotal() { totalValue = shares * shareValue; }
        
    public:
//  Constructors
        Stock();        // default constructor
        /**
         @param name Company name
         @param num Number of shares
         @param price Value of each share
         */
        Stock(const std::string& name, long num = 0, double price = 0.0);
        
//  Destructor
        ~Stock();
        
//  Methods
        /**
         Buy more shares of the same stock

         @param num Number of shares
         @param price Value of each share
         */
        void buy(long num, double price);
        
        /**
         Sell stock

         @param num Number of shares
         @param price Value of each share
         */
        void sell(long num, double price);
        
        /**
         Update the per-share value of stock

         @param price Value of each share
         */
        void update(double price);
        
        /**
         [Const] Display information about the holdings
         */
        void show() const;      // const guarantees that method doesn't alter the invoking object
    };
}

#endif /* STOCK01_H_ */
