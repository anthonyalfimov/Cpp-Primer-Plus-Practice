//
//  TvType01.hpp
//  C++ Primer Plus Practice
//
//  Created by Anthony on 11/07/2019.
//  Copyright © 2019 Anthony. All rights reserved.
//

#ifndef TvType01_hpp
#define TvType01_hpp

namespace FriendClasses101
{
    class Tv
    {
    public:
        enum {Off, On};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        
        Tv(int state = Off, int maxChannel = 125)
            : mState (state), mVolume (5), mMaxChannel (maxChannel),
              mChannel (2), mMode (Cable), mInput (TV) {}
        
        void setOnOff() { mState = (mState == On) ? Off : On; } // NB! Can be replaced by `mState ^= 1;`
        bool isOn() const { return mState == On; }
        bool volumeUp();
        bool volumeDown();
        void channelUp();
        void channelDown();
        void setMode() { mMode = (mMode == Cable) ? Antenna : Cable; }
        void setInput() { mInput = (mInput == TV) ? DVD : TV; }
        void showSettings() const;  // display all settings
        
        friend class Remote;        // Remote can access Tv private parts
        
    private:
        int mState;         // on or off
        int mVolume;        // digitised
        int mMaxChannel;    // max number of channels
        int mChannel;       // current channel
        int mMode;          // broadcast or cable
        int mInput;         // TV or DVD
    };
    
    class Remote
    {
    public:
        Remote(int mode = Tv::TV) : mMode(mode) {}
        
        bool volumeUp(Tv& t) const    { return t.volumeUp(); }
        bool volumeDown(Tv& t) const  { return t.volumeDown(); }
        void setOnOff(Tv& t) const    { t.setOnOff(); }
        void channelUp(Tv& t) const   { t.channelUp(); }
        void channelDown(Tv& t) const { t.channelDown(); }
        void setMode(Tv& t) const     { t.setMode(); }
        void setInput(Tv& t) const    { t.setInput(); }
        void setChannel(Tv& t, int channel) const;
        
    private:
        int mMode;          // controls TV or DVD
    };
    
}   // end namespace FriendClasses101

#endif /* TvType01_hpp */
