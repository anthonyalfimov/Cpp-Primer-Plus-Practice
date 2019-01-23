//
//  ClassTypeCasts101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 23/01/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "StonewtType01.hpp"

namespace
{
    void display(ClassTypeCasts101::Stonewt st, int n);
    ClassTypeCasts101::Stonewt passThrough(double pounds);
}

void showClassTypeCasts101()
{
    using namespace ClassTypeCasts101;
    
    Stonewt incognito = 275;        // converts int to double, then uses constructor to initialize
    Stonewt wolfe(285.7);           // same as Stonewt wolfe = 285.7;
    Stonewt taft(21, 8);
    
    std::cout << "The celebrity weighed ";
    incognito.showStone();
    
    std::cout << "The detective weighed ";
    wolfe.showStone();
    
    std::cout << "The president weighed ";
    taft.showPounds();
    
    incognito = 276.8;              // uses constructor for conversion
    taft = 325;                     // same as taft = Stonewt(325);
    
    std::cout << "After dinner, the celebrity weighed ";
    incognito.showStone();
    
    std::cout << "After dinner, the president weighed ";
    taft.showPounds();
    
    display(taft, 2);               // pass an object, as expected
    std::cout << "The wrestler weighed even more.\n";
    display(422, 2);                // convert into to double, then to object using constructor
                                    // this only works because the reference parameter is const
                                    //     and a temporary object is created
    std::cout << "No stone left unearned.\n";
    passThrough(200).showStone();
    std::cout << "Done.\n";
}

namespace
{
    void display(ClassTypeCasts101::Stonewt st, int n)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << "Wow! ";
            st.showStone();
        }
    }
    
    ClassTypeCasts101::Stonewt passThrough(double pounds)
    {
        return pounds;
    }
}


