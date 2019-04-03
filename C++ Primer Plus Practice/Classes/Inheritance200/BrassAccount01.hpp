//
//  BrassAccount01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 28/03/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef BrassAccount01_hpp
#define BrassAccount01_hpp

#include <string>

namespace Inheritance200
{
//  Brass Account Class
    class Brass
    {
    public:
        Brass(const std::string& fullName = "Nullbody", long accountNum = -1,
              double balance = 0.0);
        
        void deposit(double amount);
        double getBalance() const { return m_balance; }
        virtual void withdraw(double amount);       // `virtual` makes it so references and pointers
        virtual void viewAccount() const;           //     use methods from the object class, not
                                                    //     the reference or pointer class
        
        virtual ~Brass() {};                        // `virtual` destructor makes it so `delete`
                                                    //     used with a pointer envokes destructor
                                                    //     based on object type, not pointer type
                                                    //
                                                    // NB! All base classes should have
                                                    //     virtual destructors!
        
    private:
        std::string m_fullName;
        long        m_accountNum;
        double      m_balance;
    };
    
//  Brass Plus Account Class
    class BrassPlus : public Brass
    {
    public:
        BrassPlus(const std::string& fullName = "Nullbody", long accountNum = -1,
                  double balance = 0.0, double maxLoan = 500, double rate = 0.11125);
        BrassPlus(const Brass& b, double maxLoan = 500, double rate = 0.11125);
        
        virtual void withdraw(double amount) override;  // `override` ensures method is redefined
        virtual void viewAccount() const override;      //   rather than hidden by different method
        
        void resetMaxLoan(double maxLoan) { m_maxLoan = maxLoan; }
        void resetRate(double rate) { m_rate = rate; }
        void resetOwed() { m_owed = 0; }
        
    private:
        double m_maxLoan;
        double m_rate;
        double m_owed;
    };
    
}   // end namespace Inheritance200

#endif /* BrassAccount01_hpp */
