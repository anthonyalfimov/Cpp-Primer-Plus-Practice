//
//  FriendMethods101.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 16/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "TvType02.hpp"

void showFriendMethods101()
{
    using namespace FriendMethods101;
    
    Tv s42;
    std::cout << "Initial settings for 42\" TV:\n";
    s42.showSettings();
    s42.setOnOff();
    s42.channelUp();
    std::cout << "\nAdjusted settings for 42\" TV:\n";
    s42.showSettings();
    
    Remote grey;
    
    grey.setChannel(s42, 10);
    grey.volumeUp(s42);
    grey.volumeUp(s42);
    std::cout << "\n42\" settigns after using remote:\n";
    s42.showSettings();
    
    Tv s58(Tv::On);
    s58.setMode();
    grey.setChannel(s58, 28);
    std::cout << "\n58\" settigns:\n";
    s58.showSettings();
    
    std::cout << "\nDone.\n";
}
