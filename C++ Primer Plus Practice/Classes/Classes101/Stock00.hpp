//
//  Stock00.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 21/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//
//  Version 00

#ifndef STOCK00_H_
#define STOCK00_H_

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
        
        void setTotal() { totalValue = shares * shareValue; }
        
    public:
        /**
         Acquire stock in company

         @param company Company name
         @param num Number of shares
         @param price Value of each share
         */
        void acquire(const std::string& company, long num, double price);
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
         Display information about the holdings
         */
        void show();
    };
}

#endif /* STOCK00_H_ */
