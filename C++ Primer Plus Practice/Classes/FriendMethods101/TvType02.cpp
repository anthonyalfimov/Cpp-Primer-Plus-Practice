//
//  TvType02.cpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 16/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include <iostream>
#include "TvType02.hpp"

namespace FriendMethods101
{
    bool Tv::volumeUp()
    {
        if (mVolume >= MaxVal)
            return false;
        
        ++mVolume;
        return true;
    }
    
    bool Tv::volumeDown()
    {
        if (mVolume <= MinVal)
            return false;
        
        --mVolume;
        return true;
    }
    
    void Tv::channelUp()
    {
        if (mChannel < mMaxChannel)
            ++mChannel;
        else
            mChannel = 1;
    }
    
    void Tv::channelDown()
    {
        if (mChannel > 1)
            --mChannel;
        else
            mChannel = mMaxChannel;
    }
    
    void Tv::showSettings() const
    {
        std::cout << "TV is " << (mState == Off ? "Off" : "On") << "\n";
        
        if (mState == On)
        {
            std::cout
            << "Volume setting = " << mVolume << "\n"
            << "Channel setting = " << mChannel << "\n"
            << "Mode = " << (mMode == Antenna ? "Antenna" : "Cable") << "\n"
            << "Input = " << (mInput == TV ? "TV" : "DVD") << "\n";
        }
    }
    
    void Remote::setChannel(Tv& t, int channel) const
    {
        if (channel >= 1 && channel <= t.mMaxChannel)
            t.mChannel = channel;
    }
}
