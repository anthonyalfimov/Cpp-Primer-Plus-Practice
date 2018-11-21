//
//  Stock00.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 21/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "Stock00.hpp"

namespace Classes101
{
    void Stock::acquire(const std::string &co, long num, double price)
    {
        company = co;
        if (num < 0)
        {
            std::cout << "Number of shares can't be negative;"
                      << company << " shares set to 0.\n";
        }
        else
            shares = num;
        shareValue = price;
        setTotal();
    }

    void Stock::buy(long num, double price)
    {
        if (num < 0)
            std::cout << "Number of shares purchased can't be negative. "
                         "Transaction is aborted.\n";
        else
        {
            shares += num;
            shareValue = price;
            setTotal();
        }
    }

    void Stock::sell(long num, double price)
    {
        using std::cout;
        
        if (num < 0)
            cout << "Number of shares sold can't be negative. "
                    "Transaction is aborted.\n";
        else if (num > shares)
            cout << "You can't sell more than you have! "
                    "Transaction is aborted.\n";
        else
        {
            shares -= num;
            shareValue = price;
            setTotal();
        }
    }

    void Stock::update(double price)
    {
        shareValue = price;
        setTotal();
    }

    void Stock::show()
    {
        std::cout
        << "Company: " << company
        << " Shares: " << shares << "\n"
        << " Share Price: $" << shareValue
        << " Total Worth: $" << totalValue << "\n";
    }
}
