//
//  BrassAccount02.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 03/04/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef BrassAccount02_hpp
#define BrassAccount02_hpp

#include <iostream>
#include <string>

namespace AbstractBaseClass101
{
//  Abstract Base Class
    class Account
    {
    public:
        Account(const std::string& fullName = "Nullbody", long accountNumber = -1,
                double balance = 0.0);
        
        double getBalance() const { return m_balance; }
        void deposit(double amount);
        virtual void withdraw(double amount) = 0;       // pure virtual function with definition
        virtual void viewAccount() const = 0;           // pure virtual function without definition
        
        virtual ~Account() {}
        
    protected:  // members accesible for derived classes, but hidden from the interface
//      Formatting:
        struct Formatting
        {
            std::ios_base::fmtflags flag;
            std::streamsize precision;
        };
        Formatting setFormat() const;
        void restoreFormat(Formatting& f) const;
        
//      Getters:
        const std::string& getFullName() const { return m_fullName; }
        long getAccountName() const { return m_accountNum; }
        
    private:
        std::string m_fullName;
        long        m_accountNum;
        double      m_balance;
    };
    
//  Brass Account Class
    class Brass : public Account
    {
    public:
        Brass(const std::string& fullName = "Nullbody", long accountNumber = -1,
              double balance = 0.0) : Account(fullName, accountNumber, balance) {}
        
        virtual void withdraw(double amount) override;
        virtual void viewAccount() const override;
    };
    
//  Brass Plus Account Class
    class BrassPlus : public Account
    {
    public:
        BrassPlus(const std::string& fullName = "Nullbody", long accountNum = -1,
                  double balance = 0.0, double maxLoan = 500, double rate = 0.10);
        BrassPlus(const Brass& b, double maxLoan = 500, double rate = 0.10);
        
        virtual void withdraw(double amount) override;
        virtual void viewAccount() const override;
        
        void resetMaxLoan(double maxLoan) { m_maxLoan = maxLoan; }
        void resetRate(double rate) { m_rate = rate; }
        void resetOwed() { m_owed = 0; }
        
    private:
        double m_maxLoan;
        double m_rate;
        double m_owed;
    };
}   // end namespace AbstractBaseClass101

#endif /* BrassAccount02_hpp */
