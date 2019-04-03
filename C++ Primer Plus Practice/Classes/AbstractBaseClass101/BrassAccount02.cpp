//
//  BrassAccount02.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 03/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "BrassAccount02.hpp"

namespace AbstractBaseClass101
{
//  Abstract Base Class
    Account::Account(const std::string& fullName, long accountNumber, double balance)
        : m_fullName(fullName), m_accountNum(accountNumber), m_balance(balance) {}
    
    void Account::deposit(double amount)
    {
        if (amount < 0)
            std::cout << "Negative deposit not allowed; operation calncelled.\n";
        else
            m_balance += amount;
    }
    
    void Account::withdraw(double amount)               // pure virtual function can have a difinition
    {
        m_balance -= amount;
    }
    
    // Protected methods for formatting
    Account::Formatting Account::setFormat() const      // can't use Formatting unqualified here
    {
        // set ###.## format
        Formatting f;
        f.flag = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        f.precision = std::cout.precision(2);
        return f;
    }
    
    void Account::restoreFormat(Formatting& f) const    // can use Formatting unqualified in argument list
    {
        // restore format
        std::cout.setf(f.flag, std::ios_base::floatfield);
        std::cout.precision(f.precision);
    }
    
//  Brass methods
    void Brass::withdraw(double amount)
    {
        if (amount < 0)
            std::cout << "Withdrawal amount must be positive; operation cancelled.\n";
        else if (amount <= getBalance())
            Account::withdraw(amount);                  // use definition of pure virtual function
        else
            std::cout << "Withdrawal amount of $" << amount << " exceeds your balance.\n"
                         "Operation cancelled.\n";
    }
    
    void Brass::viewAccount() const
    {
        Formatting f = setFormat();     // set ###.## format and save previous formatting
        
        std::cout
            << "Brass Client: " << getFullName() << "\n"
            << "Account Number: " << getAccountName() << "\n"
            << "Balance: $" << getBalance() << "\n";
        
        restoreFormat(f);               // restore previous formatting
    }
    
//  BrassPlus methods
    
    BrassPlus::BrassPlus(const std::string& fullName, long accountNum, double balance,
              double maxLoan, double rate)
        : Account(fullName, accountNum, balance), m_maxLoan(maxLoan), m_owed(0.0), m_rate(rate) {}
    
    BrassPlus::BrassPlus(const Brass& b, double maxLoan, double rate)
        : Account(b), m_maxLoan(maxLoan), m_owed(0.0), m_rate(rate) {}  // use implicit copy-ctor
    
    void BrassPlus::withdraw(double amount)
    {
        Formatting f = setFormat();     // set ###.## format and save previous formatting
        
        double balance = getBalance();
        
        if (amount < 0)
            std::cout << "Withdrawal amount must be positive; operation cancelled.\n";
        else if (amount <= balance)
            Account::withdraw(amount);                  // use definition of pure virtual function
        else if (amount <= balance + m_maxLoan - m_owed)
        {
            double advance = amount - balance;
            m_owed += advance * (1.0 + m_rate);
            std::cout
                << "Bank advance: $" << advance << "\n"
                << "Finance charge: $" << advance * m_rate << "\n";
            deposit(advance);
            Account::withdraw(amount);
        }
        else
            std::cout << "Credit limit exceeded; operation cancelled.\n";
        
        restoreFormat(f);               // restore previous formatting
    }
    
    void BrassPlus::viewAccount() const
    {
        Formatting f = setFormat();     // set ###.## format and save previous formatting
        
        std::cout
            << "BrassPlus Client: " << getFullName() << "\n"
            << "Account Number: " << getAccountName() << "\n"
            << "Balance: $" << getBalance() << "\n";
        std::cout
            << "Maximum loan: $" << m_maxLoan << "\n"
            << "Owed to bank: $" << m_owed << "\n";
        std::cout.precision(3);     // ###.### format
        std::cout
            << "Loan rate: " << m_rate * 100 << "%\n";
        
        restoreFormat(f);               // restore previous formatting
    }
}   // end namespace AbstractBaseClass101
