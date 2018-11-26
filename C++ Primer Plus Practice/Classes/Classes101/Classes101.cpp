//
//  Classes101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 20/11/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "Stock00.hpp"

//   =============================
//   |       Main function       |
//   =============================
void showClasses101()
{
    using namespace Classes101;
    
    Stock fluffyTheCat;
    fluffyTheCat.acquire("NanoSmart", 20, 12.50);
    fluffyTheCat.show();
    
    fluffyTheCat.buy(15, 18.125);
    fluffyTheCat.show();
    
    fluffyTheCat.sell(400, 20.00);
    fluffyTheCat.show();
    
    fluffyTheCat.buy(300000, 40.125);
    fluffyTheCat.show();
    
    fluffyTheCat.sell(300000, 0.125);
    fluffyTheCat.show();
}
