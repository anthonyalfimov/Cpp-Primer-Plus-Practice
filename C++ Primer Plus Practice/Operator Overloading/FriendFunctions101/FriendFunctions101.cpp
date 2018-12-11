//
//  FriendFunctions101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/12/2018.
//  Copyright © 2018 Anthony. All rights reserved.
//

#include <iostream>
#include "myTime02.hpp"

void showFriendFunctions101()
{
    using namespace FriendFunctions100;
    
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;
    
    std::cout << "Aida and Tosca:\n";
    std::cout << aida << "; " << tosca << "\n";
    
    temp = aida + tosca;
    std::cout << "Aida + Tosca: " << temp << "\n";
    
    temp = aida * 1.17;
    std::cout << "Aida * 1.17: " << temp << "\n";
    
    std::cout << "10.0 * Tosca: " << 10.0 * tosca << "\n";
}
