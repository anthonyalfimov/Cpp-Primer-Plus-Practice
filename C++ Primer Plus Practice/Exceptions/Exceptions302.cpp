//
//  Exceptions302.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 04/12/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "Sales01.hpp"

void showExceptions302()
{
    using Exceptions302::Sales;
    using Exceptions302::LabeledSales;
    
    double monthlySales1[12]
    {
        1220, 1100, 1122, 2212, 1232, 2334,
        2884, 2393, 3302, 2922, 3002, 3544
    };
    
    double monthlySales2[12]
    {
        12, 11, 22, 21, 32, 34,
        28, 29, 33, 29, 32, 35
    };
    
    Sales sales1 (2011, monthlySales1, 12);
    LabeledSales sales2 (2012, "BlogStar", monthlySales2, 12);
    
    std::cout << "Begin try block 1\n\n";
    
    try
    {
        std::cout << "Year: " << sales1.getYear() << "\n";
        
        for (int i = 0; i < 12; ++i)
        {
            std::cout << sales1[i];
            
            if (i % 6 == 5)
                std::cout << "\n";
            else
                std::cout << " ";
        }
        
        std::cout << "\nYear: " << sales2.getYear() << "\n";
        std::cout << "Label: " << sales2.getLabel() << "\n";
        
        for (int i = 0; i < 13; ++i)
        {
            std::cout << sales2[i];
            
            if (i % 6 == 5)
                std::cout << "\n";
            else
                std::cout << " ";
        }
        
        std::cout << "\nEnd try block 1\n\n";
    }
    catch (LabeledSales::labeled_bad_index& except)
    {
        std::cout << except.what();
        std::cout << "> Label: " << except.getLabel() << "\n";
        std::cout << "> Bad index: " << except.getBadIndexValue() << "\n";
    }
    catch (Sales::bad_index& except)
    {
        std::cout << except.what();
        std::cout << "> Bad index: " << except.getBadIndexValue() << "\n";
    }
    
    std::cout << "\nBegin try block 2\n\n";
    
    try
    {
        sales2[2]  = 37.5;
        std::cout << sales2[2] << "\n";
        
        sales1[20] = 23345;
        std::cout << sales1[20] << "\n";
        
        std::cout << "\nEnd try block 2\n\n";
    }
    catch (LabeledSales::labeled_bad_index& except)
    {
        std::cout << except.what();
        std::cout << "> Label: " << except.getLabel() << "\n";
        std::cout << "> Bad index: " << except.getBadIndexValue() << "\n";
    }
    catch (Sales::bad_index& except)
    {
        std::cout << except.what();
        std::cout << "> Bad index: " << except.getBadIndexValue() << "\n";
    }
    
    std::cout << "\nDone.\n";
}
