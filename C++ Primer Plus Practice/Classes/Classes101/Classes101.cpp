//
//  Classes101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 20/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "Stock01.hpp"

//   =============================
//   |       Main function       |
//   =============================
void showClasses101()
{
    {
        using namespace Classes101;
        
        std::cout <<
        "==========================================\n"
        " Using constructors to create new objects \n"
        "==========================================\n";
        
        Stock stock1("NanoSmart", 12, 20.0);            // syntax option A for using constructor
        stock1.show();
        
        Stock stock2 = Stock("Boffo Objects", 2, 2.0);  // syntax option B for using constructor
        stock2.show();
        
        std::cout <<
        "\n==========================================\n"
        " Assigning stock1 to stock2\n"
        "==========================================\n";
        
        stock2 = stock1;
        std::cout << "Listing stock1 and stock2:\n";
        stock1.show();
        stock2.show();
        
        std::cout <<
        "\n==========================================\n"
        " Using a constructor to reset an object\n"
        "==========================================\n";
        
        stock2 = Stock("Nifty Foods", 10, 50.0);        // copy from a temp object
        std::cout << "Revised stock2:\n";
        stock2.show();
        
        std::cout <<
        "\n==========================================\n"
        " Using default constructor\n"
        "==========================================\n";
        Stock dummy;
        dummy.show();
        
        std::cout <<
        "\n==========================================\n"
        " Using list initialization\n"
        "==========================================\n";
        // Create a const object of class Stock:
        const Stock stock3 {"Sad Company"};       // list contents must match constructor parameter list;
                                                  //    here, we take advantage of default arguments
        stock3.show();
        
        std::cout <<
        "\n==========================================\n"
        " Using class methods\n"
        "==========================================\n";
        
        std::cout << "Listing stock1:\n";
        stock1.show();
        
        std::cout << "Updated stock1:\n";
        stock1.update(12.50);
        stock1.show();
        
        std::cout << "Buy more stock:\n";
        stock1.buy(15, 18.125);
        stock1.show();
        
        std::cout << "Try selling 400 stock:\n";
        stock1.sell(400, 20.00);
        stock1.show();
        
        std::cout << "Buy a lot of stock:\n";
        stock1.buy(300000, 40.125);
        stock1.show();
        
        std::cout << "Sell a lot of stock:\n";
        stock1.sell(300000, 0.125);
        stock1.show();
        
        std::cout <<
        "\n==========================================\n"
        " Object destruction follows:\n"
        "==========================================\n";
    }
    
    std::cout << "\nDone.\n";
    

}
