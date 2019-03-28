//
//  BrassAccount01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 28/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "BrassAccount01.hpp"

namespace Inheritance102
{
//  Formatting
    typedef std::ios_base::fmtflags format;
    typedef std::streamsize precision;
    
    format setFormat();
    void restore(format f, precision p);
    
//  Brass methods
    Brass::Brass(const std::string& fullName, long accountNum, double balance)
        : m_fullName(fullName), m_accountNum(accountNum), m_balance(balance)
    {
    }
    
    void Brass::deposit(double amount)
    {
        if (amount < 0)
            std::cout << "Negative deposit not allowed; operation calncelled.\n";
        else
            m_balance += amount;
    }
    
    double Brass::balance() const
    {
        return m_balance;       // why not inline this? because it's virtual?
    }
    
    void Brass::withdraw(double amount)
    {
        // set up ###.## format
        format initialState = setFormat();
        precision prec = std::cout.precision(2);
        
        if (amount < 0)
            std::cout << "Withdrawal amount must be positive; operation cancelled.\n";
        else if (amount <= m_balance)
            m_balance -= amount;
        else
            std::cout << "Withdrawal amount of $" << amount << " exceeds your balance.\n"
                         "Operation cancelled.\n";
        
        restore(initialState, prec);    // restore original format
    }
    
    void Brass::viewAccount() const
    {
        // set up ###.## format
        format initialState = setFormat();
        precision prec = std::cout.precision(2);
        
        std::cout
            << "Client: " << m_fullName << "\n"
            << "Account Number: " << m_accountNum << "\n"
            << "Balance: $" << m_balance << "\n";
        
        restore(initialState, prec);    // restore original format
    }

//  Brass plus methods
    BrassPlus::BrassPlus(const std::string& fullName, long accountNum, double balance,
                         double maxLoan, double rate)
        : Brass(fullName, accountNum, balance), m_maxLoan(maxLoan), m_owed(0.0), m_rate(rate)
    {
    }
    
    BrassPlus::BrassPlus(const Brass& b, double maxLoan, double rate)
        : Brass(b), m_maxLoan(maxLoan), m_owed(0.0), m_rate(rate)   // use implicit copy-ctor
    {
    }
    
    void BrassPlus::withdraw(double amount)
    {
        // set up ###.## format
        format initialState = setFormat();
        precision prec = std::cout.precision(2);
        
        double bal = balance();         // call member function | not redefined - no scope resolution
        
        if (amount <= bal)
            Brass::withdraw(amount);    // call base-class version | no access to base private members!
        else if (amount <= bal + m_maxLoan - m_owed)
        {
            double advance = amount - bal;
            m_owed += advance * (1.0 + m_rate);
            std::cout
                << "Bank advance: $" << advance << "\n"
                << "Finance charge: $" << advance * m_rate << "\n";
            deposit(advance);
            Brass::withdraw(amount);    // call base-class version | no access to base private members!
        }
        else
            std::cout << "Credit limit exceeded; operation cancelled.\n";
        
        restore(initialState, prec);
    }
    
    // Redefine how viewAccount() works
    void BrassPlus::viewAccount() const
    {
        // set up ###.## format
        format initialState = setFormat();
        precision prec = std::cout.precision(2);
        
        Brass::viewAccount();       // call the base-class version to display base portion
                                    //     no access to base private members!
        std::cout
            << "Maximum loan: $" << m_maxLoan << "\n"
            << "Owed to bank: $" << m_owed << "\n";
        std::cout.precision(3);     // ###.### format
        std::cout
            << "Loan rate: " << m_rate * 100 << "%\n";
        
        restore(initialState, prec);
    }
    
//  Formatting functions
    format setFormat()
    {
        // set fixed format
        return std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    }
    
    void restore(format f, precision p)
    {
        std::cout.setf(f, std::ios_base::floatfield);   // restore format
        std::cout.precision(p);                         // restore precision
    }
    
}   // end namespace Inheritance102
