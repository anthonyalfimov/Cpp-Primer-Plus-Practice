//
//  Sales01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 04/12/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef Sales01_hpp
#define Sales01_hpp

#include <stdexcept>
#include <string>

namespace Exceptions302
{
    class Sales
    {
    public:
        explicit Sales (int year);
        Sales (int year, const double* monthlySales, int numberOfMonths);
        virtual ~Sales() {}
        
        int getYear() const { return mYear; }
        
        virtual double  operator[] (int index) const;
        virtual double& operator[] (int index);
        
        class bad_index : public std::logic_error
        {
        public:
            explicit bad_index (int badIndexValue,
                               const std::string& msg = "> Index error in Sales object\n");
            virtual ~bad_index() {}
            
            int getBadIndexValue() const { return mBadIndexValue; }
        
        private:
            const int mBadIndexValue;
        };
        
    protected:
        static const int sMonths = 12;
        
    private:
        int mYear = 0;
        double mMonthlySales[sMonths];
    };
    
    class LabeledSales : public Sales
    {
    public:
        explicit LabeledSales (int year, const std::string& label = "none");
        LabeledSales (int year, const std::string& label,
                      const double* monthlySales, int numberOfMonths);
        virtual ~LabeledSales() {}
        
        const std::string& getLabel() const { return mLabel; }
        double  operator[] (int index) const override;
        double& operator[] (int index) override;
        
        class labeled_bad_index : public Sales::bad_index
        {
        public:
            labeled_bad_index (int badIndexValue, const std::string& label,
                               const std::string& msg = "> Index error in LabeledSales object\n");
            
            const std::string& getLabel() const { return mLabel; }
            ~labeled_bad_index() {}
            
        private:
            const std::string mLabel;
        };
        
    private:
        std::string mLabel;
    };
}   // end namespace Exceptions302

#endif /* Sales01_hpp */
