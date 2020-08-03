//
//  Sales01.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 04/12/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include "Sales01.hpp"

namespace Exceptions302
{
    Sales::Sales (int year) : mYear (year)
    {
        for (int i = 0; i < sMonths; ++i)
            mMonthlySales[i] = 0;
    }
    
    Sales::Sales (int year, const double *monthlySales, int numberOfMonths) : mYear (year)
    {
        int monthLimit = numberOfMonths < sMonths ? numberOfMonths : sMonths;
        int month = 0;
        
        for (; month < monthLimit; ++month)
            mMonthlySales[month] = monthlySales[month];
        
        for (; month < sMonths; ++month)
            mMonthlySales[month] = 0;
    }
    
    double Sales::operator[] (int i) const
    {
        if (i < 0 || i >= sMonths)
            throw bad_index(i);
        
        return mMonthlySales[i];
    }
    
    double& Sales::operator[] (int i)
    {
        if (i < 0 || i >= sMonths)
            throw bad_index(i);
        
        return mMonthlySales[i];
    }
    
    Sales::bad_index::bad_index(int badIndexValue, const std::string& msg)
        : std::logic_error(msg), mBadIndexValue(badIndexValue)
    {
    }
    
    LabeledSales::LabeledSales (int year, const std::string& label)
        : Sales(year), mLabel(label)
    {
    }
    
    LabeledSales::LabeledSales (int year, const std::string& label,
                                const double* monthlySales, int numberOfMonths)
        : Sales(year, monthlySales, numberOfMonths), mLabel(label)
    {
    }
    
    double LabeledSales::operator[] (int i) const
    {
        if (i < 0 || i >= sMonths)
            throw labeled_bad_index (i, getLabel());
        
        return Sales::operator[] (i);
    }
    
    double& LabeledSales::operator[] (int i)
    {
        if (i < 0 || i >= sMonths)
            throw labeled_bad_index (i, getLabel());
        
        return Sales::operator[] (i);
    }
    
    LabeledSales::labeled_bad_index::labeled_bad_index (int badIndexValue, const std::string& label,
                                                        const std::string& msg)
        : Sales::bad_index(badIndexValue, msg), mLabel(label)
    {
    }
}   // end namespace Exceptions302

